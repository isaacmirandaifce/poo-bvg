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

## Estrutura de Arquivos Exigida (Projeto_8)

Mantenha a organização estrita padrão do repositório core da disciplina:

```text
Projeto_8/
│
├── docs/
│   └── Arquitetura_Resiliencia_UML.png # Diagrama UML atualizado com o fluxo de sinais/exceções
│
├── src/
│   ├── exceptions/
│   │   └── StorageException.h          # Definição das exceções e herança de std::exception
│   │
│   ├── infrastructure/
│   │   ├── LedgerPersistence.h / .cpp  # Manipulação de arquivos (.h/.cpp)
│   │   └── SignalHandler.h / .cpp      # Configuração de ponteiro de sinal estático (.h/.cpp)
│   │
│   └── main.cpp                        # Loop de transações encapsulado por try-catch
└── README.md                           # Documentação detalhada dos testes de falha estruturados

```

---

## Fluxo de Implementação e Código Base Sugerido

### Arquivo `infrastructure/SignalHandler.h`

```cpp
#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <csignal>
#include <iostream>

class SignalHandler {
public:
    static void inicializar();
private:
    static void tratador(int sinal);
};

#endif // SIGNALHANDLER_H

```

### Arquivo `main.cpp` (A Orquestração do Engine)

O arquivo principal deve instanciar o inicializador de sinais e simular cenários de escrita em loop. Caso ocorra uma exceção, ela deve ser capturada isoladamente.

```cpp
#include <iostream>
#include "infrastructure/LedgerPersistence.h"
#include "infrastructure/SignalHandler.h"
#include "exceptions/StorageException.h"

int main() {
    SignalHandler::inicializar(); // Registra os hooks de sinal do SO

    try {
        LedgerPersistence db;
        // 1. Simular carregamento inicial (pode disparar FileCorruptedException)
        auto historico = db.carregarDados();
        
        // 2. Loop de processamento de transações (simulação)
        std::cout << "[ENGINE] Sistema operacional e aguardando interceptações..." << std::endl;
        
        // CÓDIGO DO ALUNO: Adicione lógica de simulação e persistência aqui...

    } catch (const StorageException& e) {
        std::cerr << "[CRITICAL ERROR] Falha na camada de armazenamento: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "[UNKNOWN ERROR] Erro genérico de runtime: " << e.what() << std::endl;
    }

    return 0;
}

```

---

## Rubrica de Avaliação (Tech Lead Review)

| Critério | Descrição | Pontuação |
| --- | --- | --- |
| **Tratamento de Exceções** | Criação correta da hierarquia customizada herdando de `std::exception` com polimorfismo do método `what()`? | 3.0 pts |
| **Persistência Segura** | Manipulação adequada de fluxos (`ifstream`/`ofstream`), garantindo o isolamento de erros de disco e arquivo com blocos `try-catch` locais? | 3.0 pts |
| **Captura de Sinais (OS Hooks)** | Implementação correta do tratador estático utilizando `std::signal` para interceptar `SIGINT`/`SIGTERM` e encerrar sem corromper arquivos? | 2.5 pts |
| **Modelagem e Enterprise Standard** | Arquivos bem modularizados (.h/.cpp), diagrama UML representando as exceções e boas práticas de tratamento de ponteiros? | 1.5 pts |

>  **Nota de Simulação do Ambiente:** Para testar seu tratador de sinais, execute seu programa e envie um comando de interrupção pressionando `Ctrl + C` no terminal. O programa deve interceptar o sinal, exibir a mensagem customizada definida por você no `SignalHandler::tratador` e gravar o estado final antes de fechar de forma limpa. Boa sprint!
