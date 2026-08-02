# Projeto Avaliativo 2 - Paradigma de Orientação a Objetos e UML 

## Exercício 1: Modelagem de Domínio - Seguro de Carro 
*Descrição do Contexto*

Uma empresa de seguros deseja criar um sistema para gerenciar seguros de carros. Cada seguro envolve informações sobre o cliente e o carro, além de dados específicos do seguro. Com base nas informações abaixo, modele as classes necessárias para esse sistema.

**Classes e Atributos**

- `Carro`: ano, marca, modelo, cor, placa
- `Modelo` (atributo em Carro): nome
- `Seguro`: carro, cliente, valor, vigência
- `Cliente`: nome, cpf
  
**Tarefas**
- a) Crie um diagrama de classes UML para representar as classes, incluindo seus atributos.
- b) Indique as relações entre as classes (ex: associação ou agregação).
- c) Identifique e justifique os tipos de relacionamento entre Seguro e Carro e entre Seguro e Cliente.

## Exercício 2: Detalhamento de Atributos e Métodos
*Descrição do Contexto*

Para ampliar o modelo, adicione métodos e funções nas classes para fornecer operações básicas de um sistema de seguros.

Classe `Carro`

Atributos: ano, marca, modelo, cor, placa.

Métodos: exibir_detalhes() (exibe as informações do carro), atualizar_cor(nova_cor) (modifica a cor do carro).

Classe `Cliente`

Atributos: nome, cpf.

Métodos: exibir_informacoes() (exibe o nome e o CPF do cliente).

Classe `Seguro`

Atributos: carro, cliente, valor, vigência.

Métodos: calcular_valor(base_valor, taxa) (calcula o valor do seguro com base em um valor base e uma taxa), verificar_vigencia() (retorna se o seguro ainda está válido).

**Tarefas**
- a) Escreva um diagrama de classes UML que inclua os métodos listados.
- b) Implemente uma estrutura básica de código para cada classe usando os atributos e métodos descritos.

## Exercício 3: Modelagem de Relacionamentos e Associações
*Descrição do Contexto*

O sistema de seguros agora inclui apólices de seguros para múltiplos carros de um cliente e múltiplos seguros de diferentes clientes. Cada cliente pode ter mais de um carro segurado.

**Tarefas**
- a) Atualize o diagrama de classes UML para mostrar que a classe Seguro pode ter uma associação com múltiplos objetos da classe Carro.
- b) Justifique o tipo de relacionamento (agregação ou composição) entre Seguro e Carro.
- c) Escreva uma breve explicação sobre como você representaria um cliente com múltiplos seguros em seu modelo.

## Exercício 4: Modelagem de Classes com Relações de Herança
*Descrição do Contexto*

A empresa deseja expandir o sistema de seguros para incluir outros tipos de seguros, como seguro de moto, com características específicas.

Novas Classes

`SeguroVeiculo`: uma classe base para todos os seguros de veículos.

`SeguroCarro`: herda de SeguroVeiculo e possui atributos específicos de seguro de carro.

`SeguroMoto`: herda de SeguroVeiculo e possui atributos específicos de seguro de moto.

**Tarefas**

- a) Crie um diagrama de classes UML que represente as relações de herança entre SeguroVeiculo, SeguroCarro e SeguroMoto.
- b) Explique o benefício de usar herança para representar esses diferentes tipos de seguro.
- c) Dê um exemplo de como um método calcular_valor() poderia ser implementado na classe SeguroVeiculo e sobrescrito nas classes SeguroCarro e SeguroMoto para incluir cálculos específicos.

## Exercício 5: Criação de Diagramas UML de Objetos
*Descrição do Contexto*

Com o modelo finalizado, deseja-se criar uma representação UML de objetos específicos para ilustrar o funcionamento do sistema com dados reais.

Exemplo de Dados:

`Cliente`: João Silva, CPF 123.456.789-00

`Carro`: Marca Toyota, Modelo Corolla, Ano 2020, Cor Branco, Placa XYZ-1234

`Seguro`: Valor de R$ 1.500,00, Vigência 01/01/2024 a 01/01/2025

**Tarefas**

- a) Desenhe um diagrama de objetos UML que represente a relação entre João Silva, seu Carro, e o Seguro correspondente.
- b) Identifique no diagrama os valores de atributos para cada objeto.
- c) Explique como este diagrama ajuda a visualizar a estrutura do sistema para um cliente específico.

## Exercício 6: Exercício de Abstração e Encapsulamento
*Descrição do Contexto*

A empresa de seguros quer garantir que as informações dos clientes e veículos sejam seguras e somente acessíveis por métodos específicos, usando o conceito de encapsulamento.

**Tarefas**

- a) Em uma implementação fictícia das classes Cliente e Carro, faça uso de encapsulamento, ocultando atributos como cpf e placa e expondo apenas métodos públicos para acessá-los.
- b) Escreva uma função em pseudocódigo para a classe Seguro que verifique a validade da apólice (por exemplo, se a vigência ainda é válida).
- c) Explique a importância de encapsular informações sensíveis, como CPF e placa de veículos, em sistemas de seguros.

## Entrega

- **Formato**: A entrega deverá ser feita no repositório da turma no GitHub, na pasta `Projeto_2`, com os arquivos desenvolvidos e um código de teste.
- **Prazo de Entrega**: Sete dias
