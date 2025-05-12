# Projeto 1 - Python

## Aluno: Kaique do Vale Soares

## Objetivo
Transformar um código estruturado em um código orientado a objetos, utilizando os conceitos de POO como encapsulamento, abstração e modularização.

## Estrutura

Projeto_1
src/cliente.py: Implementação da classe "Cliente, com atributos encapsulados e métodos para exibição e atualização de saldo.
test/test_cliente.py: Script de teste que cria um cliente, exibe suas informações, atualiza o saldo e exibe novamente.
docs/README.md: Documentação.

## Classe Cliente

A classe representa um cliente com alguns dados básicos. Serve como exemplo simples de encapsulamento e uso de métodos.

## Atributos

nome (str): nome completo do cliente.
idade (int): idade do cliente.
saldo (float): valor disponível na conta do cliente.

## Métodos

__init__(self, nome, idade, saldo): construtor que cria o cliente com nome, idade e saldo inicial.
mostrar_informacoes(self): exibe os dados do cliente de forma clara.
atualizar_saldo(self, novo_saldo): altera o saldo do cliente para um novo valor informado.

