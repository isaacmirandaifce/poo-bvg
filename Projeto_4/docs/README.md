# Projeto 4 - C++

## Aluno: Kaique do Vale Soares

## Objetivo
Este projeto tem como foco praticar os conceitos iniciais da linguagem C++, como:

- Criação de classes
- Métodos, construtores e funções amigas
- Uso de modificadores de acesso (public, private)
- Separação de arquivos (.h, .cpp)
- Modularização do código
- Uso do namespace std

## Estrutura

Projeto_4/  
─ docs/              - Pasta onde fica a documentação do projeto.  
─ Aluno_UML           - Diagrama uml referente a alunos
─ Disciplins_UML      - Diagrama uml referente a disciplina
─ README.md          - Documento que explica como o código funciona, descreve as classes, métodos, e dá instruções para uso e compilação.  

─ src/                - Pasta que contém os arquivos-fonte do programa (código principal).  
─ Aluno.h             - Arquivo de cabeçalho da classe Aluno, onde são declarados atributos e métodos.  
─ Aluno.cpp           - Implementação dos métodos da classe Aluno.  
─ Disciplina.h        - Arquivo de cabeçalho da classe Disciplina.  
─ Disciplina.cpp      - Implementação dos métodos da classe Disciplina.  
─ main.cpp            - Arquivo principal do programa com a função main(), responsável pela execução do sistema.  

─ teste/              - Pasta onde ficam os arquivos para teste das classes e funções do programa.  
─ test.cpp            - Código de teste para verificar se as classes e funções estão funcionando corretamente.  

## Classe Aluno

Possui os seguintes atributos privados:  

- nome (string)  
- matricula (string)  
- curso (string)  

E os seguintes métodos públicos:  

- Construtor padrão  
- Construtor parametrizado  
- void exibirInformacoes()  

## Classe Disciplina

Possui os seguintes atributos privados:  

- nome (string)  
- cargaHoraria (int)  
- nota (float)  

E os seguintes métodos públicos:  

- Construtor padrão  
- Construtor parametrizado  
- void setNota(float)  
- float getNota()  
- string getNome()  

Além disso, possui funções amigas para:  

- Verificar status de aprovação do aluno (nota >= 6.0)  

## Diagrama UML

As imagem UML mostra a estrutura das classes, seus atributos, métodos, modificadores de acesso e funções amigas, seguindo o padrão UML.
