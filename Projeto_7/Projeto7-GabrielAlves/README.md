## Projeto 7: Sistema Genérico de Filtragem e Relatórios Acadêmicos (Python)

## 1. Descrição Geral

Este projeto consiste na implementação em Python do "Projeto Avaliativo 7: Métodos e Classes Genéricas". O objetivo central é desenvolver um componente de software genérico para um sistema acadêmico, permitindo a filtragem, ordenação e manipulação de diferentes tipos de dados (como alunos, professores, etc.) de uma maneira flexível, reutilizável e escalável.
A solução demonstra a aplicação prática de conceitos de programação genérica (Generics) para resolver um problema comum de manipulação de coleções de dados, fortalecendo a modularidade e a manutenibilidade do código.

## 2. Funcionalidades Implementadas

O sistema atende a todos os requisitos funcionais e técnicos descritos no documento de avaliação:
Classe Genérica Filtro: Uma classe central que pode operar com qualquer tipo de objeto, equipada com os seguintes métodos:
adicionar_elemento(elemento: T): Para adicionar um item à coleção.
filtrar_por_condicao(condicao): Para extrair uma sublista de elementos que atendem a um critério específico, definido por uma função.
aplicar_acao_em_todos(acao): Para executar uma operação em cada um dos elementos, como a impressão de seus dados.
Integração com o Domínio Acadêmico:
Filtra alunos cuja média geral é superior a 7.0.
Identifica e lista os professores responsáveis por uma determinada disciplina.
Lista todas as disciplinas cursadas por um aluno específico em um determinado ano.
Funcionalidade Adicional de Ordenação:
Foi implementado um método de ordenação genérico que permite organizar a coleção de objetos com base em diferentes atributos (por exemplo, ordenar alunos por nome em ordem alfabética ou por média em ordem decrescente).

## 3. Tecnologias e Conceitos Aplicados

Linguagem: Python 3.
Paradigmas: Programação Orientada a Objetos (OOP) e Programação Genérica.
Módulos Principais:
typing: Utilizado para a criação de tipos genéricos (TypeVar, Generic, List, Callable), que são a base da implementação genérica em Python.
Boas Práticas: O código foi estruturado de forma modular e documentado com docstrings para garantir a legibilidade e o encapsulamento.

## 4. Estrutura de Arquivos

O projeto está organizado da seguinte maneira para promover a separação de responsabilidades:
/Projeto_7/
|-- models.py           # Definição das classes de domínio: Aluno, Professor, Disciplina, etc.
|-- filtro.py           # Implementação da classe genérica Filtro<T>.
|-- main.py             # Script principal que demonstra o uso do sistema.
|-- README.md           # Esta documentação.


## 5. Como Executar o Projeto

Para executar a demonstração, siga os passos abaixo. É necessário ter o Python 3 instalado em seu ambiente.
Clone ou faça o download do repositório e navegue até a pasta raiz do projeto.
Execute o arquivo main.py através do seu terminal:
# A partir do diretório /Projeto7-GabrielAlves
python main.py


O console exibirá os resultados de todas as operações de filtragem e ordenação, como a lista de alunos aprovados, professores de uma disciplina, e as listas ordenadas.

6. Diagrama UML

O diagrama UML abaixo ilustra a arquitetura do sistema, mostrando as classes, seus atributos, métodos e os relacionamentos entre elas. A sintaxe utilizada é a do Mermaid.
classDiagram
    direction RL

    class Filtro~T~ {
        -elementos: List~T~
        +adicionar_elemento(elemento: T)
        +filtrar_por_condicao(condicao: Callable) List~T~
        +aplicar_acao_em_todos(acao: Callable)
        +ordenar(chave: Callable, reverso: bool)
    }

    class Aluno {
        +nome: str
        +matricula_id: str
        +historico: List~Matricula~
        +calcular_media_geral(): float
    }

    class Professor {
        +nome: str
        +departamento: str
        +disciplinas_lecionadas: List~Disciplina~
    }

    class Matricula {
        +ano: int
        +nota_final: float
    }

    class Disciplina {
        +nome: str
        +codigo: str
    }

    ' --- Relacionamentos ---
    Filtro~T~ ..> "T" : manages
    Aluno "1" *-- "0..*" Matricula : possui
    Matricula "1" -- "1" Disciplina : refere-se a
    Professor "1" o-- "0..*" Disciplina : leciona




