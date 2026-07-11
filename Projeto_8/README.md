# Projeto 8 — SecureBank Pro: Motor de Persistência Resiliente + Tratador de Sinais

Implementação da camada de persistência do **Transaction Ledger** com hierarquia de exceções customizadas, manipulação segura de arquivos via `<fstream>` e captura de sinais do SO via `<csignal>`.

---

## Estrutura do Projeto

```
Projeto_8/
├── docs/
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

---

## Como Compilar

```bash
cd src/
g++ -std=c++17 -Wall -Wextra -o ../securebank_ledger \
    infrastructure/LedgerPersistence.cpp \
    infrastructure/SignalHandler.cpp \
    main.cpp
```

### Executar

```bash
cd Projeto_8/
./securebank_ledger
```

---

## Conceitos Implementados

### 1. Hierarquia de Exceções Customizadas (`StorageException.h`)

```
std::exception
    └── StorageException          ← base; sobrescreve what() como virtual
            ├── FileCorruptedException   ← arquivo existe mas está inválido
            └── DiskWriteException       ← falha de escrita/abertura
```

- Cada classe derivada injeta um prefixo identificador na mensagem, permitindo rastrear a origem no log sem depender de `typeid`.
- O `catch (const StorageException& e)` no `main.cpp` captura qualquer nó da árvore por polimorfismo.

### 2. Persistência Segura (`LedgerPersistence`)

- `salvarDados()`: abre `ledger.csv` em modo `std::ios::app`, grava cada transação com `std::flush` imediato após cada linha. Se `arquivo.fail()` retornar `true`, lança `DiskWriteException` e fecha o stream antes de propagar.
- `carregarDados()`: lê linha a linha; qualquer linha vazia lança `FileCorruptedException` com o número exato da linha corrompida. Arquivo inexistente **não** é erro — ledger novo é iniciado vazio.

### 3. Tratador de Sinais do SO (`SignalHandler`)

- `inicializar()` registra `SignalHandler::tratador` para `SIGINT` e `SIGTERM` via `std::signal()`.
- `tratador(int sinal)` é `static` — único formato aceito pelo ponteiro de função de `std::signal`.
- Ao ser acionado:
  1. Imprime alerta crítico em `stderr`.
  2. Grava `shutdown_emergency.log` com o ID do sinal.
  3. Persiste uma entrada final no `ledger.csv` registrando o encerramento.
  4. Chama `std::exit(sinal)` encerrando o processo de forma limpa.

---