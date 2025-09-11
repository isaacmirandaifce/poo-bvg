# Sistema Avançado de Gestão Acadêmica

## Aluna: Celso Vieira da Silva - ADS S3

Esse projeto é uma evolução do sistema acadêmico anterior (Projeto 6), agora expandido com um componente genérico de **filtragem e manipulação de dados**, conforme proposto no **Projeto 7**. O sistema foi desenvolvido em C++ com foco em boas práticas de orientação a objetos, modularização e reutilização de código por meio de templates.

## Descrição Geral

O sistema implementa funcionalidades como:

- **Autenticação de usuários** por meio de senha.
- **Geração de relatórios personalizados** com base no tipo de usuário.
- **Filtragem, ordenação e impressão genérica** de dados com templates.
- **Organização modular** em arquivos `.h` e `.cpp`.
- Aplicação de conceitos avançados como:
  - Classes abstratas e interfaces
  - Classes enumeradas
  - Classes internas
  - Templates genéricos
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

### Templates Genéricos

- A classe `Filtro<T>` permite manipular qualquer tipo de dado de forma genérica:
  - `adicionarElemento(T)`
  - `filtrarPorCondicao(...)`
  - `ordenarPor(...)`
  - `imprimirTodos(...)`
- Essa funcionalidade permite aplicar filtros, buscas e ordenações de forma reutilizável com alunos, professores, etc.

### Funcionalidades

- Login com senha para usuários autenticáveis.
- Relatórios diferenciados por tipo de usuário.
- Exibição de informações organizadas conforme o `TipoUsuario`.
- Filtragem de alunos por média, professores por disciplina, etc.

## Estrutura do Projeto

├── 📁 src
│ ├── Aluno.cpp
│ ├── Aluno.h
│ ├── FuncionarioAdministrativo.cpp
│ ├── FuncionarioAdministrativo.h
│ ├── Filtro.h # Classe genérica para filtragem e ordenação
│ ├── main.cpp
│ ├── Professor.cpp
│ ├── Professor.h
│ ├── Relatorio.h
│ ├── TipoUsuario.h
│ └── UsuarioAutenticavel.h
│
├── 📁 docs
│ ├── diagrama_UML.png # Diagrama UML atualizado com a classe Filtro<T>
│ └── README.md
│
├── 📁 tests
│ └── teste.cpp # Testes de autenticação, relatórios e filtros