# **Projeto Avaliativo 8: Tratamento de Exceções e Sinais - C++**

# 🎟️ Ticket #912: Motor de Persistência Resiliente e Tratador de Sinais do SO

**De:** Arquiteto de Infraestrutura / DevOps Principal (Professor)

**Para:** Engenheiro de Concorrência e Core Backend C++ (Alunos)

**Atividade:** Projeto Avaliativo 8

**Contexto:** SecureBank Pro (Subsistema: *Transaction Ledger Storage*)

**Status:** `To Do` | **Prioridade:** `Bloqueante / Crítica`

## Contexto

Olá, time! Atualmente, nosso motor de banco de dados grava as transações em arquivos planos (`.csv`). No entanto, se o disco encher, o arquivo estiver corrompido ou se um administrador encerrar o processo abruptamente via terminal (`kill -9` ou `Ctrl+C`), corremos o risco de gerar *partial writes* (escritas incompletas), corrompendo o histórico financeiro dos clientes.

Nesta sprint, sua missão é implementar uma camada de persistência ultra-resiliente utilizando **Exceções Customizadas** para falhas de arquivos e um **Manipulador de Sinais Estático** para capturar eventos de interrupção do sistema operacional. O sistema deve interceptar a queda, dar *flush* nos buffers e fechar os arquivos de forma limpa antes de encerrar.

---

##  Critérios de Aceitação (Acceptance Criteria)

### 1. Hierarquia de Exceções Customizadas (Robustez)

Não utilize exceções genéricas. Você deve criar uma árvore de exceções herdando de `std::exception` para mapear erros em tempo de execução de forma limpa:

* **`StorageException`** (Classe Base de Erro de Armazenamento): Contém um método `virtual const char* what() const noexcept override`.
* **`FileCorruptedException`** (Classe Derivada): Disparada caso o arquivo exista, mas suas colunas ou dados estejam em formato inválido ou corrompido.
* **`DiskWriteException`** (Classe Derivada): Disparada se o fluxo de escrita (`std::ofstream`) falhar ao tentar abrir ou persistir dados por falta de permissão ou espaço.

### 2. Módulo de Persistência (`LedgerPersistence`)

Esta classe será responsável pelo I/O de dados através da biblioteca `<fstream>`.

* **`void salvarDados(const std::vector<std::string>& transacoes)`**: Abre o arquivo `ledger.csv`, itera gravando as strings e força o esvaziamento do buffer (`std::flush`). Caso falhe, dispara `DiskWriteException`.
* **`std::vector<std::string> carregarDados()`**: Lê o arquivo `ledger.csv`. Se houver inconsistência nos dados (ex: linhas vazias inesperadas ou falha de leitura), dispara `FileCorruptedException`.

### 3. Tratamento de Sinais do Sistema Operacional (`SignalHandler`)

Você deve implementar uma classe estática baseada na biblioteca `<csignal>` para capturar eventos externos do SO:

* **Sinais Obrigatórios:** Interceptar **`SIGINT`** (Interrupção por Ctrl+C) e **`SIGTERM`** (Sinal de encerramento enviado pelo sistema).
* **Comportamento do Tratador:** Ao receber o sinal, o método tratador estático (`static void interceptar(int sinal)`) deve capturar o ID do sinal, imprimir um alerta crítico na tela, salvar um log emergencial de encerramento e fechar de forma segura qualquer arquivo pendente antes de invocar o `exit(sinal)`.

---

## Relatório de Testes de Falha e Resiliência

Para garantir a confiabilidade do motor de persistência do *Transaction Ledger Storage* e validar o tratamento de erros e sinais do SO, os seguintes testes estruturados foram executados.

### Resumo dos Cenários Homologados

| Cenário de Teste | Ação de Simulação (Input) | Comportamento Esperado | Status |
| :--- | :--- | :--- | :--- |
| **1. Interrupção de Sistema (SIGINT)** | Envio de sinal `Ctrl + C` durante a execução do loop. | Interceptação estática, log emergencial salvo e encerramento limpo. | `PASS` |
| **2. Arquivo Corrompido** | Adição manual de linhas em branco no `ledger.csv`. | Lançamento e captura da exceção `FileCorruptedException`. | `PASS` |
| **3. Falha de Escrita no Disco** | Remoção de permissões de gravação do arquivo (`chmod 400 ledger.csv`). | Lançamento e captura da exceção `DiskWriteException`. | `PASS` |

---

### Evidências de Execução

### Teste 1: Captura de Sinais (OS Hooks)
**Procedimento:** O programa foi executado e, durante o loop de transações, o comando `Ctrl+C` foi pressionado no terminal para acionar o `SignalHandler`.

**Saída do Terminal (Output):**
(ENGINE) Inicializando base de dados...
(ENGINE) Histórico carregado com sucesso. Registros: 0
(ENGINE) Sistema operacional e aguardando interceptações...
(DICA) Aperte Ctrl+C no terminal para ativar o SignalHandler e observar o desligamento limpo.
(ENGINE) Processando lote e gravando no Ledger...
^C
(CRITICAL ALERT) Sinal de interrupção recebido do SO (Signal ID: 2).
(ENGINE) Estado emergencial salvo. Arquivos pendentes fechados. Encerrando de forma segura.

### Teste 2: Validação de Corrupção de Arquivo
**Procedimento:** O arquivo `ledger.csv` foi modificado externamente antes da execução, inserindo-se uma linha vazia no meio dos registros para simular uma escrita incompleta (*partial write*). O programa foi executado para validar a carga inicial.

**Saída do Terminal (Output):**
(ENGINE) Inicializando base de dados...

(CRITICAL ERROR) Falha na camada de armazenamento: FileCorruptedException: Linha em branco inesperada encontrada no arquivo ledger.csv. Possível partial write passado.

### Teste 3: Restrição de Permissão e Erro de Disco
**Procedimento:** O arquivo ledger.csv teve suas permissões alteradas no sistema operacional para "somente leitura" (utilizando chmod 400 ledger.csv no Linux/macOS ou alterando as propriedades no Windows). O programa foi executado para forçar a falha no momento do envio do lote de transações.

**Saída do Terminal (Output):**
(ENGINE) Inicializando base de dados...
(ENGINE) Histórico carregado com sucesso. Registros: 5
(ENGINE) Sistema operacional e aguardando interceptações...
(DICA) Aperte Ctrl+C no terminal para ativar o SignalHandler e observar o desligamento limpo.
(ENGINE) Processando lote e gravando no Ledger...
(CRITICAL ERROR) Falha na camada de armazenamento: DiskWriteException: Falha ao abrir ou criar o arquivo ledger.csv por falta de permissão ou espaço.
