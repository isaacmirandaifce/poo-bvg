# Projeto 1 - Python

## Aluno: Gabriel Alves de Sales

## Objetivo
Transformar um código estruturado em um código orientado a objetos, utilizando os conceitos de POO como encapsulamento, abstração e modularização.

## Estrutura

Projeto_1  
 src/cliente.py → Implementação da classe Cliente, com atributos privados e métodos para exibição e atualização de saldo.  
 test/test_cliente.py → Script de teste que cria um cliente, exibe suas informações, atualiza o saldo e exibe novamente.  
 docs/README.md → Documentação do projeto.

## Classe Cliente

A classe Cliente representa um cliente com dados básicos e métodos que demonstram conceitos fundamentais de POO.

## Métodos

- __init__(self, nome, idade, saldo)`: construtor que inicializa os dados do cliente.  
- mostrar_informacoes(self): exibe os dados do cliente de forma formatada.  
- atualizar_saldo(self, valor): soma o valor informado ao saldo atual do cliente.  
- get_nome(self), get_idade(self), get_saldo(self): métodos opcionais para acesso externo aos atributos (getters).

## Atributos

- nome (str): nome completo do cliente.  
- idade (int): idade do cliente.  
- saldo (float): valor disponível na conta do cliente.

## Exemplo de uso

python
from src.cliente import Cliente

cliente1 = Cliente("Carlos Andrade", 28, 750.0)
cliente1.mostrar_informacoes()
cliente1.atualizar_saldo(250.0)
cliente1.mostrar_informacoes()
