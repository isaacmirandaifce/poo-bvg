# Projeto Avaliativo 3: Introdução a C++ — Módulo de Contatos B2B (CRM Enterprise)

Este repositório contém a solução do **Projeto Avaliativo 3**, referente ao **Ticket #612** para a migração e desenvolvimento do Módulo de Gestão de Contatos de Clientes em C++. 

O objetivo é aplicar conceitos fundamentais de Programação Orientada a Objetos (POO) em C++, como a separação de interface e implementação (`.h` e `.cpp`), uso seguro de ponteiros com `this`, gerenciamento de ciclo de vida de objetos (construtores e destrutores) e manipulação dinâmica de coleções com a STL (`std::vector`).

---

## Estrutura do Repositório

O projeto está organizado na seguinte estrutura de arquivos:

```text
Projeto_3/
│
├── docs/
│   └── Contato_UML.png         # Diagrama UML exportado
│
├── src/
│   ├── Contato.h               # Header: Declaração da classe, atributos e protótipos
│   ├── Contato.cpp             # Source: Implementação dos métodos, construtores e destrutor
│   └── main.cpp                # Ponto de entrada: Instanciação do vector e execução
│
└── README.md                   # Documentação do projeto

### Como Compilar e Executar

1. **Abra o terminal no diretório raiz do Projeto_3:**
   ```bash
   cd Projeto_3
   ```

2. **Compile todos os arquivos do módulo `src/` utilizando o `g++`:**
   ```bash
   g++ src/main.cpp src/Contato.cpp -o contato_app
   ```

3. **Execute o programa gerado:**

   * **Linux / macOS:**
     ```bash
     ./contato_app
     ```

   * **Windows:**
     ```cmd
     contato_app.exe
     ```
