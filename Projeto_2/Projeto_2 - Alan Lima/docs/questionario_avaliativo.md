### Exercício 1: Modelagem de Domínio - Seguro de Carro

**b) Indique as relações entre as classes (ex: associação ou agregação).**

Seguro e Cliente: Associação.

Seguro e Carro: Associação.

Carro e Modelo: Agregação.

**c) Identifique e justifique os tipos de relacionamento entre Seguro e Carro e entre Seguro e Cliente.**

Seguro e Carro: Associação, porque o seguro cobre um carro, mas o carro não é parte integral do seguro.

Seguro e Cliente: Associação, porque o seguro é contratado por um cliente, mas o cliente não faz parte do seguro.

### Exercício 2: Detalhamento de Atributos e Métodos

a) Escreva um diagrama de classes UML que inclua os métodos listados.

b) Implemente uma estrutura básica de código para cada classe usando os atributos e métodos descritos.

### Exercício 3: Modelagem de Relacionamentos e Associações

a) Atualize o diagrama de classes UML para mostrar que a classe Seguro pode ter uma associação com múltiplos objetos da classe Carro.

b) Justifique o tipo de relacionamento (agregação ou composição) entre Seguro e Carro.

O tipo de relacionamento entre Seguro e Carro será agregação por causa das seguintes características:

* Seguro não é dono dos  Carros **.** Os carros podem existir independentemente de um seguro.
* O seguro apenas referencia os carros cobertos pela apólice, mas não é responsável por sua criação ou destruição.

c) Escreva uma breve explicação sobre como você representaria um cliente com múltiplos seguros em seu modelo.

- Cliente terá um atributo que mantém referência para seus objetos da classe  Seguro .
- Cada Seguro terá informações detalhadas sobre os Carros que cobre.

### Exercício 4: Modelagem de Classes com Relações de Herança

a) Crie um diagrama de classes UML que represente as relações de herança entre SeguroVeiculo, SeguroCarro e SeguroMoto.

b) Explique o benefício de usar herança para representar esses diferentes tipos de seguro.

R: Permite reutilizar atributos e métodos genéricos na classe base, evitando duplicação de lógica; Torna o código mais modular e estruturado, alinhado ao conceito de polimorfismo; Atualizar a classe base automaticamente propaga as mudanças para as subclasses.

c) Dê um exemplo de como um método calcular_valor() poderia ser implementado na classe SeguroVeiculo e sobrescrito nas classes SeguroCarro e SeguroMoto para incluir cálculos específicos.

R:  Taxa adicional se o carro for blindado, custo adicional proporcional à idade do carro e taxa adicional para motos de alta cilindrada.

### Exercício 5: Criação de Diagramas UML de Objetos

a) Desenhe um diagrama de objetos UML que represente a relação entre João Silva, seu Carro, e o Seguro correspondente.

b) Identifique no diagrama os valores de atributos para cada objeto.

c) Explique como este diagrama ajuda a visualizar a estrutura do sistema para um cliente específico.

R: Ele oferece uma representação clara de instâncias reais, incluindo os dados e relacionamentos entre elas, ajudando a validar se o modelo atende aos requisitos do sistema.

### Exercício 6: Exercício de Abstração e Encapsulamento

a) Em uma implementação fictícia das classes Cliente e Carro, faça uso de encapsulamento, ocultando atributos como cpf e placa e expondo apenas métodos públicos para acessá-los.

b) Escreva uma função em pseudocódigo para a classe Seguro que verifique a validade da apólice (por exemplo, se a vigência ainda é válida).

c) Explique a importância de encapsular informações sensíveis, como CPF e placa de veículos, em sistemas de seguros.
