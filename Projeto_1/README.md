# Projeto 1 - Refatoração Estruturada para POO

Este projeto tem como objetivo refatorar um código originalmente estruturado em um código orientado a objetos, utilizando a linguagem **TypeScript**. A classe criada representa um cliente de uma loja, contendo informações como nome, idade e saldo.

## Objetivo

Transformar um código estruturado que manipulava diretamente variáveis e funções soltas em uma classe orientada a objetos, de forma mais legível, modular e escalável.


## 🧪 Teste

Para executar os testes, basta rodar o arquivo `Cliente.test.ts`. O código cria uma instância da classe `Cliente`, exibe as informações e atualiza o saldo:

```ts
const cliente1 = new Cliente("João Silva", 30, 1000);
cliente1.mostrar_informacoes();
cliente1.atualizar_saldo(500);
cliente1.mostrar_informacoes();
