# Sistema de Cliente

Um sistema simples de gerenciamento de clientes desenvolvido em Python utilizando conceitos de Programação Orientada a Objetos (POO).

## 📋 Descrição

Este projeto implementa uma classe `Cliente` que permite gerenciar informações básicas de clientes bancários, incluindo nome, idade e saldo. O sistema oferece funcionalidades para visualizar informações do cliente e atualizar o saldo da conta.

## 🚀 Funcionalidades

- **Criação de Cliente**: Instanciar um novo cliente com nome, idade e saldo inicial
- **Visualização de Informações**: Exibir dados completos do cliente
- **Atualização de Saldo**: Adicionar ou subtrair valores do saldo com validação
- **Proteção de Dados**: Atributos privados para garantir encapsulamento

## 📁 Estrutura do Projeto

```
projeto/
├── src/
│   └── cliente.py          # Classe Cliente principal
├── teste.py                # Arquivo de testes e exemplos
└── README.md              # Este arquivo
```

## 🛠️ Instalação e Uso

### Pré-requisitos

- Python 3.6 ou superior

### Como usar

1. **Clone ou baixe o projeto**
2. **Importe a classe Cliente:**

```python
from src.cliente import Cliente
```

3. **Crie uma instância do cliente:**

```python
cliente = Cliente("João Silva", 30, 1500.0)
```

4. **Use os métodos disponíveis:**

```python
# Mostrar informações
cliente.mostrar_informacoes()

# Atualizar saldo (depósito)
cliente.atualizar_saldo(500.0)

# Atualizar saldo (saque)
cliente.atualizar_saldo(-200.0)
```

## 📖 Exemplo de Uso Completo

```python
from src.cliente import Cliente

# Criar um novo cliente
cliente1 = Cliente("Marco Rocha", 21, 10000.0)

# Exibir informações iniciais
cliente1.mostrar_informacoes()
# Output: Cliente: Marco Rocha, Idade: 21, Saldo: R$10000.00

# Fazer um depósito
cliente1.atualizar_saldo(500.0)
# Output: Saldo atualizado! Novo saldo: R$10500.00

# Tentar um saque
cliente1.atualizar_saldo(-2000.0)
# Output: Saldo atualizado! Novo saldo: R$8500.00

# Tentar saque com saldo insuficiente
cliente1.atualizar_saldo(-10000.0)
# Output: Operação inválida! Saldo insuficiente.
```

## 🔧 API da Classe Cliente

### Construtor

```python
Cliente(nome: str, idade: int, saldo: float)
```

**Parâmetros:**
- `nome`: Nome completo do cliente
- `idade`: Idade do cliente em anos
- `saldo`: Saldo inicial da conta

### Métodos

#### `mostrar_informacoes() -> None`
Exibe todas as informações do cliente formatadas.

#### `atualizar_saldo(valor: float) -> None`
Atualiza o saldo do cliente.

**Parâmetros:**
- `valor`: Valor a ser adicionado (positivo) ou subtraído (negativo) do saldo

**Comportamento:**
- Se a operação resultar em saldo negativo, a transação é rejeitada
- Caso contrário, o saldo é atualizado e uma mensagem de confirmação é exibida

## 🔒 Características de Segurança

- **Encapsulamento**: Todos os atributos são privados (nome, idade, saldo)
- **Validação de Saldo**: Impede operações que resultem em saldo negativo
- **Type Hints**: Código documentado com tipos para melhor legibilidade

## 🧪 Executando os Testes

Para executar o arquivo de exemplo/teste:

```bash
python teste.py
```

**Saída esperada:**
```
Cliente: Marco Rocha, Idade: 21, Saldo: R$10000.00
Saldo atualizado! Novo saldo: R$10500.00
Cliente: Marco Rocha, Idade: 21, Saldo: R$10500.00
Saldo atualizado! Novo saldo: R$8500.00
Operação inválida! Saldo insuficiente.
Cliente: Marco Rocha, Idade: 21, Saldo: R$8500.00
```

## 🤝 Contribuindo

1. Faça um fork do projeto
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`)
3. Commit suas mudanças (`git commit -am 'Adiciona nova feature'`)
4. Push para a branch (`git push origin feature/nova-feature`)
5. Abra um Pull Request

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

## 👨‍💻 Autor

Desenvolvido como parte de estudos de Programação Orientada a Objetos em Python.

---

*Última atualização: Junho 2025*