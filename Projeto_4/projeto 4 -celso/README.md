# **Projeto Avaliativo 4: Modularização, Modificadores de Acesso e Funções Amigas - C++**

## **Objetivo**

Desenvolver um projeto prático em C++ que consolide os conhecimentos sobre modularização, modificadores de acesso (public, private, protected) e funções amigas. O tema escolhido terá utilidade prática para a vivência dos alunos de Análise e Desenvolvimento de Sistemas, reforçando conceitos fundamentais e sua aplicação no desenvolvimento de software.

---

## **Tema do Projeto: Gerenciamento de Notas de Alunos**

### **Descrição Geral**
O sistema permite o gerenciamento de notas de alunos para diferentes disciplinas. Os alunos poderão calcular médias, verificar status de aprovação/reprovação e visualizar as informações em um formato organizado.

### **Requisitos**

1. **Classes e Atributos:**
   - **Classe Aluno:**
     - Atributos: `nome` (string), `matricula` (string), `curso` (string).
     - Métodos:
       - Construtor padrão e parametrizado.
       - Métodos para exibir informações básicas do aluno (`void exibirInformacoes()`).

   - **Classe Disciplina:**
     - Atributos: `nome` (string), `cargaHoraria` (int), `nota` (float).
     - Métodos:
       - Construtor padrão e parametrizado.
       - Métodos para configurar e obter as notas (`setNota()` e `getNota()`).
       - Funções amigas para acessar as notas da disciplina e validar critérios de aprovação.

2. **Funções Amigas:**
   - Implementar uma função amiga que verifica o status de aprovação do aluno em uma disciplina. (Aprovação com nota >= 6.0).

3. **Função Principal:**
   - Criar objetos `Aluno` e associar a pelo menos duas disciplinas.
   - Exibir as informações básicas do aluno.
   - Utilizar a função amiga para verificar a aprovação do aluno em cada disciplina.

---

## **Requisitos Técnicos**

1. **Modularização:**
   - Separe a implementação em diferentes arquivos:
     - `Aluno.h`, `Aluno.cpp`.
     - `Disciplina.h`, `Disciplina.cpp`.
     - `main.cpp`.

2. **Modificadores de Acesso:**
   - Utilize modificadores adequados para garantir o encapsulamento e segurança dos atributos.

3. **Funções Amigas:**
   - Use `friend` para implementar a função de verificação de aprovação, acessando diretamente os atributos privados da classe `Disciplina`.

4. **Diagrama UML:**
   - Inclua o diagrama UML com todas as classes, atributos, métodos e relacionamentos.

---

## **Exemplo de Estrutura do Código**

### Arquivo `Aluno.h`
```cpp
#ifndef ALUNO_H
#define ALUNO_H

#endif // ALUNO_H
```

### Arquivo `Aluno.cpp`
```cpp
#include "Aluno.h"

```

### Arquivo `Disciplina.h`
```cpp
#ifndef DISCIPLINA_H
#define DISCIPLINA_H


#endif // DISCIPLINA_H
```

### Arquivo `Disciplina.cpp`
```cpp
#include "Disciplina.h"

```

### Arquivo `main.cpp`
```cpp
#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {

}
```

---

## **Critérios de Avaliação**

1. **Implementação Técnica (6 pontos):**
   - Correção da implementação das classes, funções amigas e modularização.

2. **Uso de Modificadores de Acesso e Encapsulamento (2 pontos):**
   - Aplicação correta de modificadores e encapsulamento.

3. **Modelagem UML (1 ponto):**
   - Completo e bem representado.

4. **Organização e Boas Práticas (1 ponto):**
   - Código bem estruturado e claro.

---

## **Entrega**

1. **Formato:**
   - Carregue os arquivos no repositório da turma, na subpasta `/Projetos/Projeto_4`.
   - Inclua o diagrama UML no formato `png` ou `jpg`.

2. **Prazo:**
   - A entrega deve ser realizada até **12/01/2025**.