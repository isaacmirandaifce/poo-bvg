# Projeto 1 - Conversão de Código Estruturado para Programação Orientada a Objetos (POO)

Este projeto tem como objetivo transformar um código estruturado em Python em uma versão orientada a objetos (POO).  
A refatoração aplica os princípios de **encapsulamento**, **abstração** e **modularização**, tornando o código mais organizado, legível, escalável e fácil de manter.

## Classe Implementada: `Cliente`

A classe **Cliente** representa um cliente de uma loja, armazenando seus dados e permitindo operações básicas sobre eles.

### Atributos Privados
- `__nome` (str): nome do cliente  
- `__idade` (int): idade do cliente  
- `__saldo` (float): saldo do cliente  

### Métodos
- `__init__(self, nome, idade, saldo)`: inicializa os atributos da classe.  
- `mostrar_informacoes(self)`: exibe nome, idade e saldo do cliente.  
- `atualizar_saldo(self, valor)`: atualiza o saldo com base no valor informado.  
- Métodos *getters* e *setters* para `nome` e `idade`.

## Conceitos de POO Aplicados
- **Encapsulamento:** utilização de atributos privados e acesso controlado por métodos.  
- **Abstração:** exposição apenas das funcionalidades essenciais, ocultando detalhes internos.  
- **Modularização:** organização do código em arquivos separados por classe e função.  
- **Responsabilidade Única:** a classe `Cliente` é responsável apenas por gerenciar os dados e operações de um cliente.
