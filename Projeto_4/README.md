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