# Projeto 8: Motor de Persistência Resiliente e Tratador de Sinais

Este módulo faz parte do sistema **SecureBank Pro** e é responsável pela camada de persistência de transações (`Ledger Storage`), garantindo integridade de dados e resiliência a falhas críticas do sistema operacional.

## Estrutura do Projeto
- `docs/`: Diagramas UML de arquitetura.
- `src/exceptions/`: Hierarquia de exceções customizadas para erros de I/O.
- `src/infrastructure/`: Lógica de persistência e gerenciamento de sinais do SO.
- `src/main.cpp`: Orquestração do loop de transações com tratamento de exceções.

## Funcionalidades
1. **Robustez via Exceções:** Implementação de `StorageException` e suas derivadas (`FileCorruptedException`, `DiskWriteException`) para evitar comportamento indefinido em caso de falhas de disco.
2. **Resiliência a Sinais (OS Hooks):** O módulo `SignalHandler` intercepta `SIGINT` (Ctrl+C) e `SIGTERM` para garantir o fechamento seguro de buffers (`flush`) e a integridade do arquivo `ledger.csv`.

## Como Compilar e Executar

1. **Compilação:**
   Na raiz do diretório `Projeto_8`, utilize o comando:
   ```bash
   g++ -Isrc src/main.cpp src/infrastructure/*.cpp -o secure_bank_engine
