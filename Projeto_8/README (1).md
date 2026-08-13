# Projeto 8 — Motor de Persistência Resiliente e Tratador de Sinais do SO

**Ticket:** #912
**Módulo:** SecureBank Pro — Transaction Ledger Storage
**Autor:** Breno

## 1. Objetivo

Blindar a gravação do histórico financeiro (`ledger.csv`) contra dois tipos de
falha que hoje corrompem o arquivo: (a) erros de I/O (disco cheio, sem
permissão, arquivo corrompido) e (b) encerramento abrupto do processo
(`Ctrl+C` / `kill -9` / `kill` padrão → `SIGTERM`). A solução combina uma
hierarquia de exceções customizadas com um manipulador estático de sinais do
sistema operacional.

## 2. Estrutura do Projeto

```
Projeto_8/
├── docs/
│   ├── diagrama.dot
│   └── Arquitetura_Resiliencia_UML.png
├── src/
│   ├── exceptions/
│   │   └── StorageException.h
│   ├── infrastructure/
│   │   ├── LedgerPersistence.h / .cpp
│   │   └── SignalHandler.h / .cpp
│   └── main.cpp
└── README.md
```

## 3. Hierarquia de Exceções

```
std::exception
    └── StorageException            (# mensagem, + what() noexcept override)
            ├── FileCorruptedException
            └── DiskWriteException
```

- **`StorageException`** é a classe base; `main.cpp` pode capturá-la
  polimorficamente (`catch (const StorageException&)`) para tratar qualquer
  erro de armazenamento de forma genérica, ou capturar um subtipo específico
  quando precisar de uma resposta diferenciada.
- **`FileCorruptedException`**: disparada por `carregarDados()` quando o
  `ledger.csv` existe mas contém uma linha vazia inesperada, ou quando a
  leitura falha antes do fim do arquivo (`bad()`/`fail()` sem `eof()`).
- **`DiskWriteException`**: disparada por `salvarDados()` quando o
  `std::ofstream` não consegue abrir o arquivo, quando uma escrita falha no
  meio do loop, ou quando o `std::flush` final falha.
- `what() const noexcept override` é obrigatório em `StorageException`: a
  assinatura de `std::exception::what()` já é `noexcept`, então qualquer
  exceção lançada de dentro dela levaria a `std::terminate()` — por isso o
  método apenas retorna `mensagem.c_str()`, sem nenhuma operação que possa
  falhar.

## 4. `LedgerPersistence` — por que o `std::ofstream` é atributo, não variável local

O fluxo de escrita (`fluxoSaida`) é mantido como **atributo de instância**, e
não como variável local dentro de `salvarDados()`. Isso é o que permite ao
`SignalHandler` — que roda de forma completamente assíncrona, fora do fluxo
normal do programa — acessar esse mesmo `std::ofstream` através de
`fecharComSeguranca()` e garantir `flush()` + `close()` mesmo que o sinal
chegue no meio de uma escrita. Se o stream fosse local a `salvarDados()`, o
`SignalHandler` não teria como alcançá-lo.

`fecharComSeguranca()` também grava uma linha em `emergencial.log` com
timestamp, documentando quando e que o encerramento foi seguro. É chamada em
dois lugares: pelo `SignalHandler::tratador()` (via ponteiro registrado) e
pelo destrutor de `LedgerPersistence` (para cobrir também o encerramento
normal do processo, sem sinal algum).

## 5. `SignalHandler` — limitações conhecidas (nota de arquitetura)

`std::signal()` só aceita como handler uma função livre com a assinatura
`void(*)(int)` — não um método de instância. Por isso a classe inteira é
estática, e o único jeito do handler "sem contexto" alcançar o
`LedgerPersistence` ativo é através do ponteiro estático
`persistenciaAtiva`, preenchido antes de `inicializar()` via
`registrarPersistencia()`.

**Nota honesta sobre async-signal-safety:** o padrão C++ (e o POSIX) só
garante como *async-signal-safe* um conjunto restrito de funções — chamadas
de sistema de baixo nível como `write()`, não `std::cout`, `std::ofstream`
ou alocação dinâmica de `std::string`. Nosso `tratador()` usa `std::cerr`,
`std::ofstream` e lança `std::exit()`, o que é uma simplificação didática
comum em disciplinas de C++ e suficiente para os critérios deste ticket, mas
**não é 100% seguro em produção real**: teoricamente, se o sinal chegar no
meio exato de uma alocação de heap, poderia haver um deadlock ou corrupção
de estado interno do alocador. Uma implementação de produção normalmente
usaria o padrão *"self-pipe trick"* ou apenas setaria uma
`volatile sig_atomic_t` na interrupção, deixando o loop principal (não o
handler) responsável por de fato salvar o log e fechar arquivos. Documentamos
essa limitação aqui em vez de escondê-la, pois é um trade-off consciente
entre fidelidade ao ticket (que pede o encerramento diretamente dentro de
`tratador()`) e rigor de sistemas de tempo real.

## 6. Testes de Falha Estruturados

Todos os cenários abaixo foram executados manualmente contra o binário
compilado, isolando cada falha antes de validar a próxima.

### 6.1 Execução normal + `SIGTERM` (via `timeout`)

```bash
$ timeout 3 ./projeto8
[ENGINE] Historico carregado: 0 registro(s) existente(s).
[ENGINE] Sistema operacional e aguardando interceptacoes...
[ENGINE] Lote 1/5 persistido com sucesso (3 transacoes).
[ENGINE] Lote 2/5 persistido com sucesso (3 transacoes).

[SIGNAL HANDLER] Interceptado SIGTERM (encerramento solicitado pelo SO) (codigo 15).
[SIGNAL HANDLER] Iniciando encerramento seguro do Ledger...
[SIGNAL HANDLER] Arquivos fechados sem partial writes. Encerrando processo.
```
`ledger.csv` ficou com exatamente 6 linhas completas (2 lotes × 3), nenhuma
linha truncada, e `emergencial.log` registrou o encerramento seguro.

### 6.2 `SIGINT` (Ctrl+C) explícito com `kill -s INT`

```bash
$ ./projeto8 & sleep 3; kill -s INT $!
[SIGNAL HANDLER] Interceptado SIGINT (Ctrl+C) (codigo 2).
[SIGNAL HANDLER] Iniciando encerramento seguro do Ledger...
[SIGNAL HANDLER] Arquivos fechados sem partial writes. Encerrando processo.
$ echo $?
2
```
Processo encerrou com o próprio código do sinal (`exit(sinal)`), como pedido
no ticket. `ledger.csv` novamente sem linhas incompletas.

### 6.3 `FileCorruptedException` (linha vazia inesperada)

```bash
$ printf "1,100.00,PIX\n\n3,300.00,PIX\n" > ledger.csv
$ ./projeto8
[CRITICAL ERROR] [FileCorruptedException] Linha vazia inesperada encontrada em
'ledger.csv' (registro #2).
[ENGINE] Prosseguindo com historico vazio apos falha de leitura.
```
O sistema não trava: a exceção é isolada no bloco `try/catch` de
`carregarDados()` e o engine segue operando com histórico vazio.

### 6.4 `DiskWriteException` (arquivo de destino inválido)

Simulado forçando `ledger.csv` a ser um diretório (o `open()` do
`std::ofstream` falha independentemente de permissão de usuário):

```bash
$ mkdir ledger.csv
$ ./projeto8
[CRITICAL ERROR] Falha de escrita isolada no lote 1: [DiskWriteException]
Nao foi possivel abrir 'ledger.csv' para escrita ...
[CRITICAL ERROR] Falha de escrita isolada no lote 2: [DiskWriteException] ...
[CRITICAL ERROR] Falha de escrita isolada no lote 3: [DiskWriteException] ...
[CRITICAL ERROR] Falha de escrita isolada no lote 4: [DiskWriteException] ...
[CRITICAL ERROR] Falha de escrita isolada no lote 5: [DiskWriteException] ...
[ENGINE] Simulacao concluida. Encerrando de forma limpa.
```
O `try/catch` **local** dentro do loop de lotes isola cada falha
individualmente: mesmo com 5 falhas consecutivas de escrita, o engine não
derruba o processo e termina a simulação de forma limpa — exatamente o
comportamento de resiliência pedido pela rubrica.

### 6.5 Carregamento de histórico existente e válido

```bash
$ printf "1,100.00,PIX\n2,200.00,TED\n" > ledger.csv
$ ./projeto8
[ENGINE] Historico carregado: 2 registro(s) existente(s).
```

## 7. Como compilar e executar

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2 \
    -o projeto8 src/main.cpp \
    src/infrastructure/LedgerPersistence.cpp \
    src/infrastructure/SignalHandler.cpp
./projeto8
```

Para testar o `SignalHandler` manualmente: rode `./projeto8` em um terminal e
pressione `Ctrl+C` a qualquer momento durante os 5 lotes simulados. A
mensagem customizada do `tratador()` aparece imediatamente, `ledger.csv` e
`emergencial.log` são atualizados, e o processo encerra com o código do
sinal recebido.

## 8. Rubrica — como cada critério foi atendido

| Critério | Como foi atendido |
|---|---|
| Tratamento de Exceções | `StorageException : std::exception` com `what() const noexcept override`, e `FileCorruptedException`/`DiskWriteException` derivadas, cada uma com mensagem própria |
| Persistência Segura | `salvarDados`/`carregarDados` em blocos try-catch **locais** e isolados (seção 6.3 e 6.4), sem derrubar o engine a cada falha |
| Captura de Sinais (OS Hooks) | `std::signal(SIGINT, ...)` e `std::signal(SIGTERM, ...)` registrados em `inicializar()`; `tratador(int)` imprime alerta, salva log emergencial, fecha o `ofstream` e chama `exit(sinal)` |
| Modelagem e Enterprise Standard | Separação em `exceptions/`/`infrastructure/`, diagrama UML com herança, dependências `«throws»` e o fluxo SO → SignalHandler → LedgerPersistence |
