# Projeto Avaliativo 6 – Sistema Avançado de Gestão Acadêmica

## Descrição

Este projeto foi desenvolvido como parte da disciplina de Programação Orientada a Objetos e tem como objetivo aplicar conceitos avançados de POO em C++, como:

- Classes Abstratas
- Interfaces
- Classes Enumeradas (enum)
- Classes Internas
- Polimorfismo
- Encapsulamento
- Testes automatizados

O sistema simula um ambiente acadêmico com autenticação de usuários e geração de relatórios.

## Estrutura do Projeto

```
Projeto_06/
│
├── src/
│   ├── Usuario.h / Usuario.cpp
│   ├── UsuarioAutenticavel.h
│   ├── TipoUsuario.h
│   ├── Relatorio.h
│   ├── Aluno.h / Aluno.cpp
│   ├── Professor.h / Professor.cpp
│   ├── FuncionarioAdministrativo.h / FuncionarioAdministrativo.cpp
│   └── main.cpp
│
├── testes/
│   └── testes.cpp
│
└── docs/
    └── UML_Projeto_06.pdf
```

## Funcionalidades

- Autenticação de usuários por senha
- Diferenciação de usuários por tipo (Aluno, Professor, Funcionário)
- Geração de relatórios via interface
- Histórico disciplinar encapsulado em classe interna
- Testes automatizados com assert

## Como Compilar

```bash
g++ src/*.cpp -o sistema
./sistema
```

## Como Executar os Testes

```bash
g++ src/*.cpp testes/testes.cpp -o testes
./testes
```

## Autora

Fernanda Lara Alves
