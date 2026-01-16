# Projeto Avaliativo 1: Refatoração de Código Estruturado para Programação Orientada a Objetos

## Objetivo

Transformar um código estruturado em um código orientado a objetos, implementando uma classe que usa os princípios básicos de POO, tornando o código mais legível, modular, de fácil manutenção e escalável.

## Competências Avaliadas

- Entendimento dos conceitos de POO (Orientação a Objetos).
- Habilidade de refatorar elementos de um código estruturado para o formato orientado a objetos.
- Aplicação de conceitos de classe, atributos, métodos, encapsulamento e abstração.

---

## Contexto do Projeto

No código original estruturado, temos uma aplicação simples para armazenar e manipular dados de clientes em uma loja. Este código possui variáveis e funções soltas para armazenar o nome, idade e saldo de um cliente, bem como funções para mostrar informações e atualizar o saldo. Essa abordagem pode gerar um código menos modular e escalável.

### Código Estruturado Original

```python
# Variáveis globais
nome_cliente = "João Silva"
idade_cliente = 30 
saldo_cliente = 1000.0

# Função para exibir as informações do cliente
def mostrar_informacoes():
    print(f"Cliente: {nome_cliente}, Idade: {idade_cliente}, Saldo: {saldo_cliente}")

# Função para atualizar o saldo do cliente
def atualizar_saldo(valor):
    global saldo_cliente
    saldo_cliente += valor
```

### Tarefa

Refatore o código acima para uma estrutura orientada a objetos, implementando uma classe `Cliente` com os atributos e métodos que representem as funcionalidades originais. A nova classe deve adotar os princípios de POO, incluindo encapsulamento e abstração.

---

## Especificações do Projeto

1. **Nome da Classe**: `Cliente`

2. **Atributos**:
   - `nome` (str): Nome do cliente.
   - `idade` (int): Idade do cliente.
   - `saldo` (float): Saldo do cliente.

3. **Métodos**:
   - `__init__(self, nome, idade, saldo)`: Construtor para inicializar os atributos do cliente.
   - `mostrar_informacoes(self)`: Método para exibir as informações do cliente (similar à função `mostrar_informacoes`).
   - `atualizar_saldo(self, valor)`: Método para atualizar o saldo do cliente (similar à função `atualizar_saldo`).

4. **Conceitos de POO aplicados**:
   - **Encapsulamento**: Os atributos `nome`, `idade` e `saldo` devem ser privados, acessíveis apenas por meio dos métodos da classe.
   - **Abstração**: A lógica de atualização e exibição de informações deve estar dentro da classe, simplificando o uso para quem interage com a classe `Cliente`.
   - **Facilidade de manutenção**: Ao isolar os dados e a lógica do cliente na estrutura de uma classe, o código se torna mais fácil de expandir no futuro.

---

## Instruções de Desenvolvimento

1. **Desenvolvimento da Classe**  
   Escreva o código para a classe `Cliente` de acordo com as especificações. 

2. **Implementação dos Conceitos de POO**  
   Ao desenvolver a classe, garanta:
   - Implementação correta do **encapsulamento** utilizando atributos privados (`__atributo`).
   - Manter uma **estrutura modular e organizada** para facilitar futuras manutenções.

3. **Teste da Classe**  
   Escreva um código simples para criar instâncias de `Cliente`, exibir suas informações e atualizar o saldo. Exemplo de uso:

   ```python
   cliente1 = Cliente("João Silva", 30, 1000.0)
   cliente1.mostrar_informacoes()
   cliente1.atualizar_saldo(500.0)
   cliente1.mostrar_informacoes()
   ```

---

## Critérios de Avaliação

1. **Implementação da Classe** (3 pontos)  
   - A classe deve estar de acordo com as especificações e incluir os atributos e métodos necessários.

2. **Aplicação dos Conceitos de POO** (4 pontos)  
   - Uso correto de encapsulamento e abstração.
   - Clareza e modularidade do código.

3. **Testes e Funcionamento** (2 pontos)  
   - A classe e seus métodos devem funcionar corretamente, com os valores exibidos e atualizados conforme o esperado.

4. **Organização e Documentação** (1 ponto)  
   - Código organizado e, se possível, com comentários explicativos.

---

## Entrega

- **Formato**: A entrega deverá ser feita no repositório da turma no GitHub, na pasta `Projeto_1`, com um arquivo contendo a classe `Cliente` e um código de teste.
- **Prazo de Entrega**: Sete dias

