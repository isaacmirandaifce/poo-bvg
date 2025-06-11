# 📘 Projeto Avaliativo 5 – Sistema Acadêmico com Herança, Polimorfismo, Sobrecarga e Sobrescrita (C++)

# Aluna: Leticia Carvalho da Silva - ADS S3

## 🎯 Objetivo

Esse projeto tem como objetivo aplicar os conceitos de **Herança**, **Polimorfismo**, **Sobrecarga** e **Sobrescrita** em C++, por meio da construção de um sistema de gerenciamento acadêmico que lida com diferentes tipos de usuários: Alunos, Professores, Funcionários Administrativos e Monitores.

---

## 🧠 Conceitos Utilizados

- **Herança**: As classes `Aluno`, `Professor` e `FuncionarioAdministrativo` herdam da classe base `Usuario`. A classe `Monitor` herda de forma múltipla de `Aluno` e `Professor`.

- **Polimorfismo**: Usado para manipular diferentes tipos de usuários através de ponteiros do tipo `Usuario*`, permitindo chamada dinâmica do método `gerarRelatorio()`.

- **Sobrescrita (override)**: Cada classe derivada implementa sua própria versão do método virtual `gerarRelatorio()`.
- **Sobrecarga (overload)**: A classe `Aluno` possui o método `exibirDetalhes` sobrecarregado, permitindo exibição com ou sem notas.

- **Herança virtual**: Evita ambiguidade na classe `Monitor`, que herda de `Aluno` e `Professor`, ambos herdando de `Usuario`.

---

## 📂 Estrutura do Projeto

├── 📁 src 
│ ├── Aluno.h
│ ├── Aluno.cpp
│ ├── Professor.h
│ ├── Professor.cpp
│ ├── FuncionarioAdministrativo.h
│ ├── FuncionarioAdministrativo.cpp
│ ├── Monitor.h
│ ├── Monitor.cpp
│ ├── Usuario.h
│ ├── Usuario.cpp
│ └── main.cpp
│
├── 📁 docs
│ └── UML_class.png # Diagrama UML mostrando as classes e heranças
│ └── README.md
