# Sistema Avançado de Gestão Acadêmica - Projeto 8

## Aluna: Celso Vieira da Silva - ADS S3

Esse projeto é uma evolução do sistema acadêmico desenvolvido anteriormente (Projetos 6 e 7), agora ampliado para incluir **tratamento de exceções** e **resposta a sinais do sistema operacional**, conforme proposto no **Projeto 8**. O objetivo é tornar o sistema mais robusto, tolerante a falhas e resiliente a eventos inesperados, mantendo as funcionalidades anteriores.

---

## Descrição Geral

O sistema gerencia usuários acadêmicos (alunos, professores, funcionários administrativos) com:

- Carregamento automático de dados a partir de arquivos CSV.
- Tratamento de exceções para leitura, gravação e manipulação segura dos arquivos.
- Resposta a sinais do sistema operacional como encerramento abrupto (`SIGINT`), término (`SIGTERM`) e falha de segmentação (`SIGSEGV`).
- Funcionalidades já implementadas: autenticação, geração de relatórios, filtragem e ordenação genérica via templates.

---

## Funcionalidades e Conceitos Aplicados

### Tratamento de Exceções

- O sistema lança exceções específicas para erros ao abrir arquivos, falta de permissão, ou problemas na conversão de dados.
- As exceções são capturadas e tratadas para evitar crashes e permitir mensagens claras ao usuário.

### Tratamento de Sinais do Sistema Operacional

- Implementação de um `SinalHandler` que captura sinais como `SIGINT`, `SIGTERM` e `SIGSEGV`.
- Permite que o programa execute rotinas de limpeza ou encerre de forma controlada diante de falhas ou interrupções.

### Funcionalidades Existentes (dos projetos anteriores)

- Autenticação segura com senha para usuários.
- Relatórios personalizados conforme o tipo do usuário.
- Filtragem, ordenação e impressão genérica de coleções com templates.
- Classes abstratas, interfaces, classes internas e enumerações para organização do código.

---

## Estrutura do Projeto

├── 📁 src
│ ├── Aluno.cpp
│ ├── Aluno.h
│ ├── FuncionarioAdministrativo.cpp
│ ├── FuncionarioAdministrativo.h
│ ├── Filtro.h
│ ├── main.cpp
│ ├── Professor.cpp
│ ├── Persistencia.cpp # Implementação do carregamento e salvamento de dados
│ ├── Persistencia.h
│ ├── SinalHandler.cpp # Implementação do tratamento de sinais do sistema
│ ├── SinalHandler.h
│ ├── Professor.h
│ ├── Relatorio.h
│ ├── TipoUsuario.h
│ └── UsuarioAutenticavel.h
│
├── 📁 docs
│ ├── diagrama_UML.png # Diagrama UML atualizado com tratamento de sinais e exceções
│ └── README.md
│
├── 📁 tests
│ └── teste.cpp # Testes de autenticação, relatórios, filtros e persistência
│ └── alunos_teste.csv
│
├── 📁 dados
│ ├── alunos.csv
│ ├── professores.csv