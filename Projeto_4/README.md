# Projeto 4: Gerenciamento de Notas de Alunos em C++

---

## 🚀 Visão Geral do Projeto

Este projeto em C++ é um sistema simples para o gerenciamento de notas de alunos em diferentes disciplinas. Ele foi desenvolvido com foco em consolidar os conceitos de **modularização**, **modificadores de acesso** (`public`, `private`, `protected`) e **funções amigas**.

É uma aplicação prática que simula um cenário comum na área de Análise e Desenvolvimento de Sistemas, permitindo calcular médias, verificar status de aprovação/reprovação e exibir informações de forma organizada.

---

## ✨ Funcionalidades

* **Cadastro de Alunos:** Armazena nome, matrícula e curso.
* **Cadastro de Disciplinas:** Inclui nome, carga horária e a nota do aluno na disciplina.
* **Cálculo de Aprovação:** Uma função amiga verifica se o aluno foi aprovado em uma disciplina (nota `GPA >= 6.0`).
* **Exibição de Informações:** Permite visualizar os dados básicos do aluno e o status de aprovação em cada disciplina.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++
* **Compilador:** G++ (GNU C++ Compiler)

---

## 📂 Estrutura do Projeto

O projeto segue uma estrutura modular bem definida para facilitar a organização e a manutenção do código:

Projeto_4/
├── src/               # Código-fonte principal
│   ├── Aluno.h        # Definição da classe Aluno
│   ├── Aluno.cpp      # Implementação da classe Aluno
│   ├── Disciplina.h   # Definição da classe Disciplina e declaração da função amiga
│   ├── Disciplina.cpp # Implementação da classe Disciplina e da função amiga
│   └── main.cpp       # Ponto de entrada do programa (exemplo de uso)
├── docs/              # Documentação do projeto (ex: Diagrama UML)
│   └── UML_Diagram.png
└── tests/             # Diretório para testes automatizados (vazio neste exemplo)

---

## ⚙️ Como Compilar e Executar

Siga os passos abaixo para compilar e executar o projeto em seu ambiente:

1.  **Navegue até o diretório `src`**:
    Abra seu terminal ou prompt de comando e entre na pasta `src` do projeto:

    ```bash
    cd Projeto_4/src
    ```

2.  **Compile os arquivos C++**:
    Use o `g++` para compilar os arquivos-fonte e criar o executável.

    ```bash
    g++ Aluno.cpp Disciplina.cpp main.cpp -o gerenciador_notas
    ```
    * `-o gerenciador_notas`: Define o nome do arquivo executável como `gerenciador_notas` (você pode escolher outro nome, se preferir).

3.  **Execute o programa**:
    Após a compilação, execute o programa:

    ```bash
    ./gerenciador_notas
    ```

---