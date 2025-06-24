# Sistema Avançado de Gestão Acadêmica

## Aluna: Leticia Carvalho da Silva - ADS S3

Esse projeto é um sistema acadêmico modularizado em C++ que permite o gerenciamento de diferentes tipos de usuários alunos, professores e funcionários administrativos, com autenticação e geração de relatórios. Ele foi desenvolvido com foco na aplicação de conceitos avançados de orientação a objetos.

## Descrição Geral

O sistema implementa funcionalidades como:

- **Autenticação de usuários** por meio de senha.
- **Geração de relatórios personalizados** com base no tipo de usuário.
- **Organização e modularização** em arquivos `.h` e `.cpp`.
- Aplicação de conceitos avançados como:
  - Classes abstratas e interfaces
  - Classes enumeradas
  - Classes internas
  - Encapsulamento

## Funcionalidades e Conceitos Aplicados

### Classes Abstratas

- `UsuarioAutenticavel` é uma classe abstrata derivada de `Usuario`.
  - Possui o método puro: `bool autenticar(std::string senha)`.

### Interfaces

- A interface `Relatorio` define o método `gerarRelatorio()`, implementado por `Aluno`, `Professor` e `FuncionarioAdministrativo`.

### Classes Enumeradas

- `TipoUsuario` é uma enumeração com os valores:
  - `ALUNO`, `PROFESSOR`, `FUNCIONARIO_ADMINISTRATIVO`.

### Classes Internas

- A classe `Aluno` contém uma classe interna chamada `HistoricoDisciplinar`.
  - Armazena nome da disciplina, ano cursado e nota.

### Funcionalidades

- Login com senha para usuários autenticáveis.
- Relatórios diferenciados por tipo de usuário.
- Exibição de informações organizadas conforme o `TipoUsuario`.

## Estrutura do Projeto

├── 📁 src 
│ ├── Aluno.cpp
│ ├── Aluno.h
│ ├── FuncionarioAdministrativo.cpp
│ ├── FuncionarioAdministrativo.h
│ ├── main.cpp
│ ├── Usuario.cpp
│ ├── Usuario.h
│ ├── Professor.cpp
│ ├── Professor.h
│ ├── Relatorio.h
│ └── TipoUsuario.h
│ └── UsuarioAutenticavel.h
│
├── 📁 docs
│ └── diagrama_UML.png # Diagrama UML mostrando as classes e seus relacionamentos
│ └── README.md
│
├── 📁 tests
│ └── teste.cpp # Um teste simples demonstrando a autenticação e o uso dos relatórios polimórficos.
