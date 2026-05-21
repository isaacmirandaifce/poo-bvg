# Projeto 7 - Métodos e Classes Genéricas em C++

## Informações Acadêmicas

- **Aluno:** Gabriel Uaren  
- **Curso:** ADS (Análise e Desenvolvimento de Sistemas)  
- **Turma:** 3° Semestre  
- **Turno:** Tarde  
- **Disciplina:** Programação Orientada a Objetos  
- **Professor:** Isaac  

---

## Objetivo

Criar uma classe genérica utilizando Templates em C++ para armazenar, filtrar e processar diferentes tipos de dados.

---

## Tecnologias Utilizadas

- C++
- Templates
- STL (vector)
- std::function
- Expressões Lambda

---

## Funcionalidades

- Adicionar elementos ao pipeline
- Filtrar elementos usando lambdas
- Processar elementos com ações personalizadas

---

## Classes Utilizadas

- DataFilter<T>
- Transacao
- LogSeguranca

---

## Exemplo de Uso

O sistema permite:

- Filtrar transações acima de determinado valor
- Filtrar logs críticos
- Processar dados dinamicamente

---

## Compilação

```bash
g++ main.cpp Transacao.cpp LogSeguranca.cpp -o programa