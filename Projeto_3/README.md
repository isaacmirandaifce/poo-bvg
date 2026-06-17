# **Projeto Avaliativo 3: Introdução a C++**

## **Objetivo**
Este projeto tem como objetivo introduzir conceitos fundamentais da linguagem C++ e reforçar os tópicos abordados em aula, como criação de classes, uso de métodos, containers (`vector`), manipulação de strings, namespaces e estruturação de código.

---

## **Descrição do Projeto**

1. **Classe Pessoa:**
   - **Atributos:**
     - `std::string nome`: Nome da pessoa.
     - `std::string telefone`: Telefone da pessoa.
   - **Métodos:**
     - Construtor padrão.
     - Construtor parametrizado (inicializa os atributos `nome` e `telefone` com valores fornecidos).
     - Destrutor (exibe uma mensagem indicando a destruição do objeto).
     - `void imprimirNome()`: Imprime o nome da pessoa.
     - `void imprimirTelefone()`: Imprime o telefone da pessoa.
     - Utilizar o ponteiro `this` dentro da classe para demonstrar boas práticas.

2. **Função `main`:**
   - Criar um container `std::vector` para armazenar objetos do tipo `Pessoa`.
   - Adicionar pelo menos 3 objetos `Pessoa` ao `vector`.
   - Percorrer o `vector` utilizando um laço e imprimir o nome e telefone de cada pessoa armazenada.

3. **Modelagem UML:**
   - Criar um diagrama UML que represente a classe `Pessoa`, seus atributos e métodos.

4. **Estrutura de Arquivos:**
   - `Pessoa.h`: Declaração da classe.
   - `Pessoa.cpp`: Implementação da classe.
   - `main.cpp`: Contém a função principal e manipulação do `vector`.

---

## **Requisitos Técnicos**

1. **Classes e Métodos:**
   - Utilize atributos privados e métodos públicos.
   - Implementação do destrutor para exibir mensagens de limpeza.

2. **Namespaces:**
   - Utilize `namespace std` para simplificar a escrita do código.

3. **Manipulação de Containers (`vector`):**
   - Armazenar e manipular objetos do tipo `Pessoa` usando o container `std::vector`.

4. **Entrada e Saída de Dados:**
   - Utilize `std::cout` e `std::cin` para manipulação de entrada e saída.

---

## **Estrutura do Código**

### Arquivo `Pessoa.h`
```cpp
#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:

public:

};

#endif // PESSOA_H
```

### Arquivo `Pessoa.cpp`
```cpp
#include "Pessoa.h"

// Construtor padrão

// Construtor parametrizado

// Destrutor

// Metodo de impressao do nome

// Metodo de impressao do nome

```

### Arquivo `main.cpp`
```cpp
#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {

    // Criando objetos Pessoa e adicionando ao vector

    // Percorrendo o vector e exibindo informações
    for () {
        
    }

    return 0;
}
```

---

## **Diagrama UML**
Os alunos devem criar um diagrama UML que represente:
- A classe `Pessoa` com seus atributos e métodos.
- Os tipos de dados de cada atributo e o escopo dos métodos (público ou privado).

O diagrama deve ser salvo como `Pessoa_UML.png` ou similar e carregado no repositório.

---

## **Critérios de Avaliação**

1. **Implementação Técnica (6 pontos):**
   - Estrutura correta dos arquivos (`.h` e `.cpp`).
   - Implementação correta dos atributos, métodos, construtores e destrutores.

2. **Uso de Containers (2 pontos):**
   - Utilização correta de `std::vector` para armazenar e manipular objetos.

3. **Modelagem UML (1 ponto):**
   - Criação do diagrama UML da classe `Pessoa`.

4. **Organização e Boas Práticas (1 ponto):**
   - Organização do código e uso adequado de comentários.

---

## **Entrega**

1. **Repositório GitHub:**
   - Submeta os arquivos no repositório da turma no diretório `/Projetos/Projeto_3`.
   - Siga as regras de contribuição definidas previamente para o repositório.

2. **Prazo:**
   - Sete dias

3. **Arquivos Necessários:**
   - `Pessoa.h`, `Pessoa.cpp`, `main.cpp` (código-fonte).
   - `Pessoa_UML.png` (diagrama UML).
