# Guia de Uso da Classe Cliente

A classe `Cliente` é usada para representar informações básicas de um cliente, incluindo nome, idade e saldo. Ela também oferece métodos para exibir as informações do cliente, atualizar o saldo e acessar os atributos de forma controlada.

## Como Usar

### Inicialização
Crie uma instância de `Cliente` fornecendo `nome`, `idade` e `saldo` como argumentos:

```python
from cliente import Cliente

# Criando uma instância de Cliente
cliente = Cliente(nome="Maria", idade=30, saldo=1000.50)
```

# Métodos Disponíveis
- mostrar_informacoes()
Exibe as informações do cliente (nome, idade e saldo) formatadas em uma string.

- cliente.mostrar_informacoes()
Saída: Cliente: Maria, Idade: 30, Saldo: 1000.5

- atualizar_saldo(valor)
Atualiza o saldo do cliente somando o valor fornecido. O valor pode ser positivo ou negativo.

- cliente.atualizar_saldo(500)
print(cliente.get_saldo())  # Saída: 1500.5

- cliente.atualizar_saldo(-200)
print(cliente.get_saldo())  # Saída: 1300.5
