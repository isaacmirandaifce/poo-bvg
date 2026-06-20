# Projeto Avaliativo 8 - Tratamento de Exceções e Sinais

## Descrição

Este projeto implementa uma camada de persistência resiliente para armazenamento de transações financeiras utilizando C++. O sistema foi desenvolvido para lidar com falhas de leitura e escrita em arquivos através de exceções customizadas e para interceptar sinais do sistema operacional, permitindo o encerramento seguro da aplicação.

O objetivo é garantir maior confiabilidade no armazenamento de dados, evitando perda de informações e corrupção de arquivos em situações de erro ou interrupção inesperada do programa.

## Funcionalidades

### Hierarquia de Exceções

O projeto utiliza uma hierarquia de exceções baseada em `std::exception`:

* `StorageException`: classe base para erros de armazenamento.
* `FileCorruptedException`: lançada quando o arquivo apresenta dados inválidos ou corrompidos.
* `DiskWriteException`: lançada quando ocorre falha na gravação de dados.

### Persistência de Dados

A classe `LedgerPersistence` é responsável por:

* Salvar transações no arquivo `ledger.csv`.
* Carregar transações previamente armazenadas.
* Detectar falhas de leitura e escrita.
* Garantir o descarregamento do buffer utilizando `std::flush`.

### Tratamento de Sinais

A classe `SignalHandler` intercepta:

* `SIGINT` (Ctrl + C)
* `SIGTERM`

Ao receber um sinal:

1. Exibe uma mensagem de alerta na tela.
2. Registra o evento em `emergency.log`.
3. Realiza o encerramento seguro da aplicação.

## Estrutura do Projeto

```text
Projeto_8/
│
├── docs/
│   └── Arquitetura_Resiliencia_UML.png
│
├── src/
│   ├── exceptions/
│   │   └── StorageException.h
│   │
│   ├── infrastructure/
│   │   ├── LedgerPersistence.h
│   │   ├── LedgerPersistence.cpp
│   │   ├── SignalHandler.h
│   │   └── SignalHandler.cpp
│   │
│   └── main.cpp
│
└── README.md
```

## Classes Implementadas

### StorageException

Classe base para todas as exceções relacionadas ao armazenamento de dados.

### FileCorruptedException

Especialização utilizada para indicar arquivos corrompidos ou inconsistentes.

### DiskWriteException

Especialização utilizada para indicar falhas de gravação em disco.

### LedgerPersistence

Classe responsável pela persistência dos dados utilizando arquivos.

Métodos implementados:

* `salvarDados()`
* `carregarDados()`

### SignalHandler

Classe responsável por registrar e tratar sinais enviados pelo sistema operacional.

Métodos implementados:

* `inicializar()`
* `tratador()`

## Como Compilar

Utilizando o compilador g++:

```bash
g++ src/main.cpp src/infrastructure/LedgerPersistence.cpp src/infrastructure/SignalHandler.cpp -o projeto8
```

## Como Executar

Linux:

```bash
./projeto8
```

Windows:

```bash
projeto8.exe
```

## Testes Realizados

### Teste de Persistência

* Inicialização do sistema.
* Carregamento de transações existentes.
* Inserção de novas transações.
* Gravação das informações em `ledger.csv`.

### Teste de Exceções

Foram realizados testes para:

* Falha na leitura de arquivos.
* Falha na gravação de arquivos.
* Tratamento das exceções customizadas.

### Teste de Interrupção por Sinal

Procedimento:

1. Executar a aplicação.
2. Pressionar `Ctrl + C`.
3. Verificar a exibição da mensagem de alerta.
4. Confirmar a criação do arquivo `emergency.log`.
5. Confirmar o encerramento seguro da aplicação.

## Tecnologias Utilizadas

* C++
* Programação Orientada a Objetos
* STL (Standard Template Library)
* `<fstream>`
* `<vector>`
* `<string>`
* `<exception>`
* `<csignal>`

## Objetivos de Aprendizagem

Durante o desenvolvimento deste projeto foram aplicados os seguintes conceitos:

* Tratamento de exceções customizadas.
* Herança e polimorfismo.
* Manipulação de arquivos.
* Programação orientada a objetos.
* Tratamento de sinais do sistema operacional.
* Organização modular de código em arquivos `.h` e `.cpp`.

## Autor

**Gabriel Uaren**

Aluno do **Instituto Federal de Educação, Ciência e Tecnologia do Ceará (IFCE) – Campus Boa Viagem**.

Disciplina: **Programação Orientada a Objetos (POO)**

Projeto desenvolvido como atividade avaliativa da disciplina, com foco na implementação de mecanismos de persistência resiliente, tratamento de exceções e captura de sinais do sistema operacional utilizando a linguagem C++.

**Instituição:** IFCE – Campus Boa Viagem
**Curso:** ADS
**Professor:** Isaac Miranda
**Disciplina:** Programação Orientada a Objetos
**Projeto:** Projeto Avaliativo 8
**Tema:** Tratamento de Exceções e Sinais em C++
