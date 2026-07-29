# Projeto 7 - Motor Genérico de Filtragem e Processamento (C++ Templates) - SecureBank Pro

Este repositório contém a implementação do **Projeto Avaliativo 7 / Ticket #815**, focado no desenvolvimento do motor de Data Analytics genérico do sistema em C++.

O objetivo principal é eliminar a duplicação de códigos de filtragem utilizando **Classes Genéricas (Templates)** em conjunto com **`std::function` e expressões lambda** para injeção de regras de negócio.

---

## 🎟️ Ticket #815: Motor Genérico de Filtragem e Processamento (C++ Templates)

**De:** Arquiteto de Software (Professor)  
**Para:** Engenheiro de Dados C++ (Alunos)  
**Projeto:** SecureBank Pro (Módulo de Data Analytics)  
**Status:** `To Do` | **Prioridade:** `Alta`

### 📝 Contexto

Olá, equipe!  
Atualmente, nosso sistema possui várias classes de filtro (`FiltroTransacao`, `FiltroLogAcesso`, `FiltroCliente`), todas fazendo exatamente a mesma coisa: iterando sobre um `vector` e aplicando regras condicionais (ex: "Filtrar transações acima de R$10.000" ou "Filtrar logs de erro críticos"). Isso viola o princípio DRY (*Don't Repeat Yourself*).

Sua missão nesta sprint é unificar essa lógica criando uma **Classe Genérica (Template Class)** chamada `DataFilter<T>`. Esse componente será o coração do nosso novo Pipeline de Dados e deverá ser capaz de armazenar, filtrar e executar ações sobre **qualquer** tipo de objeto que passarmos para ele.

---

## Critérios de Aceitação (Acceptance Criteria)

1. **A Classe Genérica `DataFilter<T>`:**
   Você deve criar uma classe baseada em `template <typename T>` que possua um container interno (`std::vector<T>`) para armazenar os dados. A classe deve implementar os seguintes métodos:
   * **`adicionar(T elemento)`**: Adiciona um novo elemento ao pipeline.
   * **`filtrar(std::function<bool(const T&)> condicao)`**: Recebe uma função (ou expressão lambda) como regra de negócio e retorna um novo `vector<T>` contendo apenas os elementos que passaram no teste.
   * **`processar(std::function<void(const T&)> acao)`**: Recebe uma função que executa uma ação (ex: imprimir na tela, ou gravar em log) para cada elemento armazenado.

2. **Integração e Testes (Classes de Domínio):**
   Para provar que sua classe genérica funciona com tipos diferentes, crie duas classes distintas no seu `main.cpp`:
   * **Classe `Transacao`**: Contém `id`, `valor` e `tipo` ("PIX", "TED").
   * **Classe `LogSeguranca`**: Contém `timestamp`, `nivel` ("INFO", "CRITICAL") e `mensagem`.

3. **Diagrama UML:**
   O diagrama de classes deve representar a classe template `DataFilter<T>` com a notação UML correta (uma caixa tracejada no canto superior direito da classe indicando o parâmetro de tipo `T`), além de mostrar sua relação de uso com as classes de domínio.

---

## 📂 Estrutura do Repositório

```text
Projeto_7/
│
├── docs/
│   └── Diagrama_DataFilter_UML.png    # Diagrama UML com notação de Template e dependências
│
├── src/
│   ├── DataFilter.h                   # Classe template universal (declaração e implementação inline)
│   ├── Transacao.h / .cpp             # Domínio de dados 1 (Transações financeiras)
│   ├── LogSeguranca.h / .cpp          # Domínio de dados 2 (Logs de auditoria e criticidade)
│   └── main.cpp                       # Orquestração do pipeline de dados com lambdas
│
└── README.md                          # Documentação técnica do projeto

## Como Compilar e Executar

1. **Abra o terminal no diretório raiz do Projeto_7:**
   ```bash
   cd Projeto_7
   ```

2. **Compile todos os arquivos do módulo `src/` utilizando o `g++` (C++11 ou superior):**
   ```bash
   g++ -std=c++11 src/main.cpp src/Transacao.cpp src/LogSeguranca.cpp -o datafilter_app
   ```

3. **Execute o programa gerado:**

   * **Linux / macOS:**
     ```bash
     ./datafilter_app
     ```

   * **Windows:**
     ```cmd
     datafilter_app.exe
     ```
