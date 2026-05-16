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

## Uso da friend function

A funcao validarTransacao foi implementada como friend para permitir acesso controlado aos atributos privados e protegidos das classes ContaBancaria e Transacao.

Dessa forma, o sistema de auditoria consegue validar transacoes sem utilizar getters publicos, aumentando a seguranca e mantendo o encapsulamento.

