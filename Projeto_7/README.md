# Projeto 7 - Motor Genérico de Filtragem e Processamento (C++ Templates) - SecureBank Pro

Este repositório contém a implementação do **Projeto Avaliativo 7 / Ticket #815**, focado no desenvolvimento do motor de Data Analytics genérico do sistema em C++.

O objetivo principal é eliminar a duplicação de códigos de filtragem utilizando **Classes Genéricas (Templates)** em conjunto com **`std::function` e expressões lambda** para injeção de regras de negócio.

---

## Estrutura do Repositório

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
