# Projeto 1 - Refatoração de Código Estruturado para POO

Este projeto tem como objetivo refatorar um código estruturado em Python, transformando o mesmo em um código orientado a objetos (POO). A refatoração aplica os conceitos de encapsulamento, abstração e modularização, tornando o código mais legível, escalável e de fácil manutenção.

A classe implementada é a Cliente, que representa um cliente de uma loja com seus dados e operações básicas.

Os atributos privados são:
- __nome (str): Nome do cliente
- __idade (int): Idade do cliente
- __saldo (float): Saldo do cliente

Métodos utilizados:
- __init__(self, nome, idade, saldo): o qual inicializa os atributos.
- mostrar_informacoes(self): o qual exibe nome, idade e saldo.
- atualizar_saldo(self, valor): responsável por atualizar o saldo do cliente.
- Métodos getters e setters para nome e idade.


Conceitos de POO  que foram aplicados nesse projeto:
- Encapsulamento: atributos privados e acesso controlado via métodos.
- Abstração: ocultação dos detalhes internos, expondo apenas o essencial.
- Modularização: cada classe e função em seu próprio arquivo.
- Responsabilidade única: a classe Cliente lida apenas com dados e operações de um cliente.

