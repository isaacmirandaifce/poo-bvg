````md
# Projeto Avaliativo 7 — Métodos e Classes Genéricas em C++

## Descrição

Este projeto foi desenvolvido como atividade avaliativa da disciplina de Programação Orientada a Objetos em C++.

O objetivo principal é implementar uma classe genérica utilizando templates, permitindo armazenar, filtrar e processar diferentes tipos de dados de maneira reutilizável e escalável.

O sistema simula um pequeno pipeline de análise de dados do SecureBank Pro, aplicando filtros em transações bancárias e logs de segurança utilizando expressões lambda e recursos da STL.

---

# Objetivos do Projeto

- Aplicar conceitos de Templates em C++
- Utilizar Programação Genérica
- Trabalhar com `std::vector`
- Utilizar `std::function`
- Aplicar expressões lambda
- Implementar reutilização de código
- Representar a arquitetura utilizando UML

---

# Estrutura do Projeto

```txt
Projeto_7/
│
├── docs/
│   └── Diagrama_DataFilter_UML.png
│
├── src/
│   ├── DataFilter.h
│   ├── Transacao.h
│   ├── Transacao.cpp
│   ├── LogSeguranca.h
│   ├── LogSeguranca.cpp
│   └── main.cpp
│
└── README.md
````

---

# Classe Genérica DataFilter<T>

A classe `DataFilter<T>` foi desenvolvida utilizando templates para permitir o armazenamento e processamento de qualquer tipo de objeto.

## Métodos implementados

### adicionar(T elemento)

Adiciona um novo elemento ao container interno.

### filtrar(std::function<bool(const T&)> condicao)

Recebe uma função ou expressão lambda responsável por aplicar uma condição de filtragem aos dados armazenados.

Retorna um novo `vector<T>` contendo apenas os elementos aprovados pela condição.

### processar(std::function<void(const T&)> acao)

Executa uma ação personalizada para cada elemento armazenado.

---

# Classes de Domínio

## Classe Transacao

Representa uma transação bancária contendo:

* id
* valor
* tipo

### Exemplo

```cpp
Transacao(1, 12000, "PIX");
```

---

## Classe LogSeguranca

Representa registros de segurança do sistema contendo:

* timestamp
* nivel
* mensagem

### Exemplo

```cpp
LogSeguranca(
    "2025-05-23",
    "CRITICAL",
    "Tentativa de invasao"
);
```

---

# Tecnologias Utilizadas

* C++
* Templates
* STL
* std::vector
* std::function
* Expressões Lambda
* UML

---

# Exemplo de Filtragem

## Filtrar transações acima de R$5000

```cpp
auto suspeitas =
    filtroTransacoes.filtrar(
        [](const Transacao& t) {
            return t.getValor() > 5000;
        }
    );
```

---

# Exemplo de Logs Críticos

```cpp
auto logsCriticos =
    filtroLogs.filtrar(
        [](const LogSeguranca& log) {
            return log.getNivel() == "CRITICAL";
        }
    );
```

---

# Compilação

A compilação pode ser realizada utilizando o g++.

## Comando

```bash
g++ main.cpp Transacao.cpp LogSeguranca.cpp -o programa
```

---

# Execução

## Linux / Git Bash

```bash
./programa
```

## Windows

```bash
programa.exe
```

---

# Saída Esperada

```txt
TRANSACOES SUSPEITAS
ID: 2 VALOR: 8000 TIPO: TED
ID: 3 VALOR: 12000 TIPO: PIX

LOGS CRITICOS
2025-05-23 - CRITICAL - Tentativa de invasao
```

---

# UML

O projeto contém um diagrama UML representando:

* Classe genérica `DataFilter<T>`
* Relação com `Transacao`
* Relação com `LogSeguranca`

Arquivo:

```txt
docs/Diagrama_DataFilter_UML.png
```

---

# Autor

Ivamilton Ferreira da Silva Junior

---

# Considerações Finais

O projeto demonstra a aplicação prática de programação genérica em C++, promovendo reutilização de código, flexibilidade e organização arquitetural através do uso de templates e programação funcional com lambdas.

```
```
