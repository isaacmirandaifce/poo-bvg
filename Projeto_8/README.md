# Projeto Avaliativo 8 - Gerenciamento Acadêmico Resiliente (C++)

## 🎯 Objetivo
Este projeto tem como objetivo aprimorar o sistema acadêmico existente com a integração de tratamento de **exceções** e **sinais** do sistema operacional, promovendo maior robustez, resiliência e segurança na manipulação de dados.

## 📌 Tema
**Gerenciamento Acadêmico Resiliente**

Um sistema acadêmico capaz de:

- Carregar e salvar dados de forma persistente a partir de arquivos externos.
- Tratar exceções comuns na manipulação de arquivos, como:
  - Arquivo não encontrado.
  - Permissão negada.
  - Erros de leitura e conversão.
- Responder adequadamente a sinais do sistema operacional:
  - `SIGINT` (Ctrl+C)
  - `SIGSEGV` (Falha de segmentação)
  - `SIGTERM` (Finalização solicitada)

## 🗂 Estrutura de Diretórios

```
Projeto_8/
│
├── docs/
│ └── UML.md # Diagrama UML do sistema
│
├── src/
│ ├── Aluno.h
│ ├── Disciplina.h
│ ├── Excecoes.h
│ ├── main.cpp
│ ├── Persistencia.h
│ ├── Persistencia.cpp
│ ├── Professor.h
│ ├── SinalHandler.h
│ ├── SinalHandler.cpp
│ ├── SistemaAcademico.h
│ └── SistemaAcademico.cpp
│
└── test/ # Casos de teste (em desenvolvimento)
```


## 🛠 Requisitos Técnicos

- 📁 Persistência:
  - Salvamento e carregamento automático dos dados do sistema.
  - Detecção de falhas em tempo de execução e exceções personalizadas.
- ⚠️ Exceções:
  - `ArquivoNaoEncontradoException`
  - `PermissaoNegadaException`
  - `FalhaConversaoException`
- 🧠 Sinais:
  - Tratamento com `<csignal>` para evitar perda de dados em falhas.
- 🧩 Modularização:
  - Código organizado em `.h` e `.cpp` para reuso e clareza.

## ▶️ Execução

Para compilar o projeto:
```bash
g++ -std=c++11 -g -o sistema_academico src/main.cpp src/Persistencia.cpp src/SinalHandler.cpp src/SistemaAcademico.cpp
```

## 📚 Autores
Projeto desenvolvido com fins educativos como parte da disciplina de Programação Orientada a Objetos.
