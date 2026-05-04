# **Projeto Avaliativo 3: Introdução a C++**

## **Objetivo**

Este projeto tem como objetivo introduzir conceitos fundamentais da linguagem C++ e reforçar os tópicos abordados em aula, como criação de classes, uso de métodos, containers (`vector`), manipulação de strings, namespaces e estruturação de código.

---

# 🎟️ Ticket #612: Desenvolvimento do Módulo de Contatos B2B (C++)

**De:** Arquiteto de Software (Professor)  
**Para:** Desenvolvedor C++ Júnior (Alunos)  
**Projeto:** CRM Enterprise (Módulo de Alta Performance)  
**Status:** `To Do` | **Prioridade:** `Alta`

##  Contexto
Olá, equipe!
Como parte da nossa migração de sistemas legados para uma arquitetura de alta performance, estamos reescrevendo o **Módulo de Gestão de Contatos de Clientes (CRM)** utilizando **C++**. 

Nossa antiga aplicação sofria com vazamentos de memória e uso de arrays de tamanho fixo, o que causava travamentos quando o número de clientes crescia. Sua missão nesta *Sprint* é criar a fundação desse novo módulo utilizando boas práticas de C++: separação de interface e implementação (`.h` e `.cpp`), uso seguro de ponteiros (`this`) e alocação dinâmica com a biblioteca padrão (STL `std::vector`).

---

## Critérios de Aceitação (Acceptance Criteria)

Para que sua **Pull Request (PR)** seja aprovada no *Code Review*, o código deve cumprir os seguintes requisitos arquiteturais:

### Fase 1: Arquitetura da Classe (Header e Source)
1. **Interface (`Contato.h`):** Declare a classe `Contato` (substituindo a antiga classe genérica 'Pessoa'). Ela deve ter os atributos privados estritamente tipados: `std::string nome` e `std::string telefone`.
2. **Implementação (`Contato.cpp`):** Implemente os métodos da classe. 
    * Crie um **construtor parametrizado** que utilize obrigatoriamente o ponteiro `this` para diferenciar os parâmetros dos atributos da classe.
    * Crie um **destrutor** (`~Contato()`) que imprima no console um log de sistema avisando que o contato foi removido da memória (Ex: `"LOG: Contato [Nome] desalocado da memória."`).
    * Implemente os métodos `imprimirNome()` e `imprimirTelefone()`.

### Fase 2: Motor Principal e Containers (STL)
1. **Módulo Executável (`main.cpp`):** Não utilizaremos mais arrays fixos em C (ex: `Contato contatos[10]`). Você deve utilizar o container dinâmico **`std::vector<Contato>`**.
2. **Processamento:** * Instancie pelo menos 3 contatos de clientes corporativos usando o método `push_back()`.
    * Crie um laço de repetição (iteração) para percorrer o `vector`, imprimindo os dados de cada contato na tela de forma formatada.

### Fase 3: Documentação UML
Assim como no projeto anterior, o *Gap Semântico* deve ser reduzido. Crie o **Diagrama de Classes UML** da classe `Contato`, especificando a visibilidade (público/privado) e os tipos de dados do C++.

---

##  Estrutura de Arquivos Exigida (Projeto_3)

Em projetos reais de C++, separar o que é "declaração" do que é "código executável" é lei. Seu repositório deverá ter exatamente esta estrutura:

```text
Projeto_3/
│
├── docs/
│   └── Contato_UML.png         # Diagrama de Classes
│
├── src/
│   ├── Contato.h               # Header: Declaração da classe e atributos
│   ├── Contato.cpp             # Source: Lógica dos construtores, destrutor e métodos
│   └── main.cpp                # Ponto de entrada: #include "Contato.h" e uso do std::vector
│
└── README.md                   # Instruções de como compilar o código (ex: g++ main.cpp Contato.cpp)
```

---

## Como Entregar (Fluxo GitHub)

1. No seu fork local, navegue até a pasta `Projeto_3`.
2. Desenvolva o código garantindo que não haja erros de compilação.
3. **Dica de Compilação:** Lembre-se que em C++ você precisa compilar os arquivos `.cpp` juntos. Se usar GCC, o comando será algo como: `g++ src/main.cpp src/Contato.cpp -o crm_app`.
4. Faça o *Push* e abra a **Pull Request (PR)** com o título: `Projeto_3 - [Seu Nome Completo]`.

---

##  Rubrica de Avaliação (Tech Lead Review)

Sua entrega será avaliada nos seguintes pilares (Total: 10 pontos):

| Critério | Descrição | Pontuação |
| :--- | :--- | :--- |
| **Arquitetura C++ (.h e .cpp)** | Os arquivos foram separados corretamente? O `.h` possui as guardas de inclusão (`#ifndef`, `#define`) ou `#pragma once`? | 3.0 pts |
| **Gerenciamento de Memória** | O construtor usa o `this->` corretamente? O destrutor foi implementado e emite o log quando os objetos saem de escopo? | 2.0 pts |
| **Domínio da STL (std::vector)** | O `main.cpp` usa a biblioteca `<vector>` de forma correta, populando com `push_back` e iterando sem estourar o limite? | 3.0 pts |
| **UML e Organização** | O diagrama UML está correto? O código está bem indentado e documentado? | 2.0 pts |

> **Dica:** Prestem muita atenção na importação de bibliotecas padrão como `<iostream>`, `<string>` e `<vector>`. Lembrem-se também do `std::` ou declarem o `using namespace std;` de forma consciente no `main.cpp`. C++ dá muito poder ao desenvolvedor, mas exige grande responsabilidade com a memória. Mostrem o que sabem!
## **Entrega**

1. **Repositório GitHub:**
   - Submeta os arquivos no repositório da turma no diretório `/Projetos/Projeto_3`.
   - Siga as regras de contribuição definidas previamente para o repositório.

2. **Prazo:**
   - Sete dias

3. **Arquivos Necessários:**
   - `Pessoa.h`, `Pessoa.cpp`, `main.cpp` (código-fonte).
   - `Pessoa_UML.png` (diagrama UML).
