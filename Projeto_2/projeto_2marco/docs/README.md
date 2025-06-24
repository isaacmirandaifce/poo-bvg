# Sistema de Seguros Veiculares 🚗🏍️

Um sistema completo de gerenciamento de seguros para veículos desenvolvido em Python utilizando conceitos avançados de Programação Orientada a Objetos (POO), incluindo herança, encapsulamento e polimorfismo.

## 📋 Descrição

Este projeto implementa um sistema robusto para gerenciamento de seguros veiculares, permitindo o cadastro de clientes, veículos (carros e motos) e a criação de apólices de seguro com diferentes características. O sistema demonstra conceitos fundamentais da POO como herança, encapsulamento e composição.

## 🚀 Funcionalidades

- **Gestão de Clientes**: Cadastro e gerenciamento de informações de clientes
- **Gestão de Veículos**: Suporte para carros e motos com informações detalhadas
- **Sistema de Seguros**: Criação de apólices personalizadas para diferentes tipos de veículos
- **Herança**: Implementação de classes base e especializadas
- **Encapsulamento**: Proteção de dados sensíveis como CPF e placa
- **Validação de Vigência**: Verificação automática de validade das apólices
- **Cálculo de Valores**: Sistema flexível para cálculo de prêmios

## 🏗️ Arquitetura do Sistema

O sistema utiliza herança para criar uma hierarquia de classes:

```
SeguroVeiculo (Classe Base)
├── SeguroCarro (Herda de SeguroVeiculo)
└── SeguroMoto (Herda de SeguroVeiculo)
```

## 📁 Estrutura do Projeto

```
projeto_2marco/
├── src/
│   ├── __init__.py         # Inicialização do pacote
│   ├── cliente.py          # Classe Cliente
│   ├── carro.py            # Classe Carro
│   ├── seguro_veiculo.py   # Classe base SeguroVeiculo
│   └── seguro.py           # Classes SeguroCarro e SeguroMoto
├── tests/
│   └── main.py             # Arquivo principal com exemplos
├── docs/                   # Documentação adicional
└── README.md               # Este arquivo
```

## 🛠️ Instalação e Uso

### Pré-requisitos

- Python 3.6 ou superior

### Como usar

1. **Clone ou baixe o projeto**
2. **Execute o sistema:**

```bash
cd projeto_2marco
python tests/main.py
```

**Ou navegue até a pasta raiz e execute:**

```bash
python -m tests.main
```

## 📖 Exemplo de Uso Completo

```python
import sys
import os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'src'))

from cliente import Cliente
from carro import Carro
from seguro import SeguroCarro

# Criando um cliente
cliente = Cliente("João Silva", "123.456.789-00")

# Criando um carro
carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")

# Criando um seguro para o carro
seguro = SeguroCarro(cliente, carro, 1500.00, "2024-01-01 a 2025-01-01")

# Exibindo os detalhes do seguro
print(seguro.exibir_detalhes())

# Atualizando a cor do carro
carro.atualizar_cor("Preto")
print(f"Carro atualizado: {carro.exibir_detalhes()}")

# Verificando vigência
print("Seguro válido:", seguro.verificar_vigencia("2024-06-15"))
```

**Saída esperada:**
```
Seguro do carro: Toyota Corolla, Ano: 2020, Cor: Branco, Placa: XYZ-1234, Cliente: Nome: João Silva, CPF: 123.456.789-00, Valor: R$1500.00, Vigência: 2024-01-01 a 2025-01-01
Carro atualizado: Toyota Corolla, Ano: 2020, Cor: Preto, Placa: XYZ-1234
Seguro válido: True
```

## 🔧 API das Classes

### Classe Cliente

```python
Cliente(nome: str, cpf: str)
```

**Métodos:**
- `exibir_informacoes()`: Retorna informações formatadas do cliente
- `get_cpf()`: Retorna o CPF (atributo encapsulado)

### Classe Carro

```python
Carro(ano: int, marca: str, modelo: str, cor: str, placa: str)
```

**Métodos:**
- `exibir_detalhes()`: Retorna detalhes completos do veículo
- `atualizar_cor(nova_cor: str)`: Atualiza a cor do veículo
- `get_placa()`: Retorna a placa (atributo encapsulado)

### Classe SeguroVeiculo (Base)

```python
SeguroVeiculo(cliente: Cliente, valor: float, vigencia: str)
```

**Métodos:**
- `calcular_valor(base_valor: float, taxa: float)`: Calcula o valor do seguro
- `verificar_vigencia(data_atual: str)`: Verifica se o seguro está válido

### Classe SeguroCarro (Herança)

```python
SeguroCarro(cliente: Cliente, carro: Carro, valor: float, vigencia: str)
```

**Métodos:**
- `exibir_detalhes()`: Exibe detalhes específicos do seguro de carro

### Classe SeguroMoto (Herança)

```python
SeguroMoto(cliente: Cliente, moto: Moto, valor: float, vigencia: str)
```

**Métodos:**
- `exibir_detalhes()`: Exibe detalhes específicos do seguro de moto

## 🔒 Características de Segurança

- **Encapsulamento**: CPF do cliente e placa do veículo são atributos privados
- **Validação de Vigência**: Sistema robusto para verificar validade das apólices
- **Herança Bem Estruturada**: Código reutilizável e extensível
- **Composição**: Relacionamento entre classes bem definido

## 🏛️ Conceitos de POO Demonstrados

### 1. **Encapsulamento**
- Atributos privados (`__cpf`, `__placa`)
- Métodos getters para acesso controlado

### 2. **Herança**
- `SeguroCarro` e `SeguroMoto` herdam de `SeguroVeiculo`
- Uso de `super()` para chamar o construtor da classe pai

### 3. **Polimorfismo**
- Método `exibir_detalhes()` implementado diferentemente em cada classe filha

### 4. **Composição**
- Classes `Seguro` contêm objetos `Cliente` e `Veiculo`

## 🧪 Executando o Sistema

Para executar o exemplo completo:

```bash
# Opção 1: Executar diretamente
cd projeto_2marco
python tests/main.py

# Opção 2: Executar como módulo (recomendado)
python -m tests.main
```

## ⚠️ Solução de Problemas

### Erro de ImportError/ModuleNotFoundError

Se você encontrar erros de importação, certifique-se de:

1. **Criar arquivo `__init__.py` vazio** na pasta `src/`:
```bash
touch src/__init__.py
```

2. **Corrigir importações no `seguro.py`**:
```python
# Se estiver na mesma pasta
from .seguro_veiculo import SeguroVeiculo

# Ou importação absoluta
from seguro_veiculo import SeguroVeiculo
```

3. **Executar a partir da pasta raiz** do projeto:
```bash
cd projeto_2marco
python tests/main.py
```

## 🔄 Extensibilidade

O sistema foi projetado para ser facilmente extensível. Para adicionar novos tipos de veículos:

1. Crie uma nova classe de veículo (ex: `Moto`)
2. Crie uma nova classe de seguro herdando de `SeguroVeiculo`
3. Implemente o método `exibir_detalhes()` específico

## 🤝 Contribuindo

1. Faça um fork do projeto
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`)
3. Commit suas mudanças (`git commit -am 'Adiciona nova feature'`)
4. Push para a branch (`git push origin feature/nova-feature`)
5. Abra um Pull Request

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

## 👨‍💻 Autor

Desenvolvido como parte de estudos avançados de Programação Orientada a Objetos em Python, demonstrando conceitos de herança, encapsulamento e polimorfismo.

---

