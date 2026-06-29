# **Projeto Avaliativo 8: Tratamento de Exceções e Sinais - C++**

## **Tema do Projeto: Gerenciamento Acadêmico Resiliente**

### **Descrição Geral**
Os alunos devem modificar o sistema acadêmico para incluir:
- **Carregamento de dados a partir de arquivos**, garantindo que a aplicação seja capaz de iniciar com dados pré-existentes e salvos anteriormente.
- **Tratamento de exceções** ao tentar abrir, ler e gravar arquivos de dados.
- **Mecanismo de resposta a sinais do sistema operacional**, garantindo que falhas inesperadas sejam tratadas e que a aplicação possa continuar funcionando ou encerrar de maneira segura.

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