Este projeto tem como objetivo refatorar um código estruturado (baseado em variáveis e funções soltas) para o paradigma de Programação Orientada a Objetos (POO), aplicando os conceitos de classe, atributos, métodos, encapsulamento e abstração.

A classe Clientes representa um cliente de uma loja e possui três atributos principais:

__nome: armazena o nome do cliente e é um atributo privado;
__idade: que guarda a idade do cliente e também é privado;
__saldo: que representa o saldo do cliente, igualmente privado.

A classe conta ainda com três métodos principais:

O método init(self, nome, idade, saldo) é o construtor, responsável por inicializar os atributos da classe.
O método mostrar_informacoes(self) exibe os dados do cliente, como nome, idade e saldo.
O método atualizar_saldo(self, valor) atualiza o saldo do cliente com base em um valor recebido.