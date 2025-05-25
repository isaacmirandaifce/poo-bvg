# Sistema de Gerenciamento de Seguros de Veículos

Esse projeto simula um sistema orientado a objetos para gerenciamento de seguros de veículos, com foco em carros e motos. Ele foi desenvolvido como parte da atividade avaliativa sobre modelagem orientada a objetos.


## Estrutura do Projeto

Projeto_2 - Leticia Carvalho/ 
├── src/ # código-fonte
│ ├── carro.py
│ ├── cliente.py
│ ├── modelo.py
│ ├── seguro.py

├── tests/ # arquivo de teste
│ └── teste_seguro.py

├── docs/ # documentação e diagrama UML
│ ├── UML_class.png
│ └── README.md


## Funcionalidades

- Criação e gerenciamento de clientes e veículos.
- Associações entre seguros e múltiplos carros.
- Herança entre diferentes tipos de seguros.
- Verificação de vigência de apólices com `datetime`.
- Encapsulamento de dados sensíveis como CPF e placa.
- Cálculo de valor de seguro com base em taxa personalizada.


## Classes Principais

### `Modelo`
- Representa o modelo de um carro.
- Atributo: `nome`.

### `Carro`
- Atributos: ano, marca, modelo (`Modelo`), cor, placa.
- Métodos:
  - `exibir_detalhes()`
  - `atualizar_cor(nova_cor)`

### `Cliente`
- Atributos: nome, CPF (encapsulado).
- Métodos:
  - `exibir_informacoes()`

### `SeguroVeiculo` (classe base)
- Atributos: cliente, valor, vigência.
- Métodos:
  - `calcular_valor(base_valor, taxa)`
  - `verificar_vigencia()`

### `SeguroCarro` / `SeguroMoto`
- Herança de `SeguroVeiculo`
- `SeguroCarro`: pode associar múltiplos carros.
- `SeguroMoto`: pode ter dados específicos de motos.
