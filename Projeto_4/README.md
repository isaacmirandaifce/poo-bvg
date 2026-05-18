# Projeto 4 - SecureBank Pro

## IDENTFICAÇÃO:

Aluno: Gabriel Uaren
Turma: 3° Semestre de ADS - TARDE

## Objetivo

O projeto tem como objetivo demonstrar os conceitos de:

- Modularizacao em C++
- Modificadores de acesso
- Encapsulamento
- Funcoes amigas (friend)

## Uso do protected

O atributo saldo foi definido como protected para permitir que futuras subclasses da classe ContaBancaria possam acessar diretamente esse atributo.

Isso facilita a extensao do sistema bancario, permitindo criar classes derivadas como:

- ContaInvestimento
- ContaPoupanca
- ContaPremium

sem quebrar o encapsulamento total da classe.
# 🎟️ Ticket #704: Módulo de Auditoria de Transações Bancárias (C++)

**De:** CTO / Arquiteto de Segurança (Professor)

**Para:** Desenvolvedor Backend (Alunos)

**Projeto:** SecureBank Pro

**Status:** `To Do` | **Prioridade:** `Crítica`

##  Contexto

Olá, time! No setor bancário, a integridade dos dados é nossa maior prioridade. Atualmente, temos o desafio de permitir que um sistema externo de **Auditoria** verifique se uma transação financeira é legítima, sem que os detalhes sensíveis da conta do cliente fiquem expostos para o resto do sistema.

Nesta sprint, utilizaremos o conceito de **Funções Amigas (`friend`)** para dar permissão especial de acesso ao módulo de auditoria, e o modificador **`protected`** para organizar nossa hierarquia de contas, garantindo o encapsulamento exigido pelas normas bancárias.

## Uso da friend function


