### Como usar 
**Navegue ate a pasta teste e utilize o framework NODE.js para executar no terminal do seu VScode. Exemplo: node testeTodos.js**

### Respostas

### Exercício 1: Representação do Domínio - Seguro de Carro

B - Relacionamentos entre as classes:

Seguro e Cliente: Associação.
Seguro e Carro: Associação.
Carro e Modelo: Agregação.

C - Identifique e explique os tipos de relação entre Seguro e Carro e Seguro e Cliente:

Seguro e Carro: Trata-se de uma associação, pois o seguro cobre um carro, mas o carro pode existir sem estar relacionado a um seguro específico.

Seguro e Cliente: Também é uma associação, já que o seguro é contratado por um cliente, mas o cliente não é parte integrante do seguro.

### Exercício 3: Relacionamentos e Associações

B - Explique o tipo de relação entre Seguro e Carro (agregação ou composição):

Entre Seguro e Carro, o relacionamento é de agregação, pois:
O seguro não é proprietário dos carros.
Os carros podem existir de forma independente do seguro.
O seguro apenas referencia os carros cobertos pela apólice, sem responsabilidade sobre sua criação ou destruição.

C - Descreva como modelar um cliente com vários seguros:

A classe Cliente deve ter um atributo que armazene referências para seus objetos da classe Seguro.
Cada Seguro conterá os dados sobre os Carros que ele cobre.

### Exercício 4: Herança no Modelo de Classes

B - Benefícios da herança para modelar diferentes tipos de seguros:

Facilita o reaproveitamento de atributos e métodos comuns na classe base.
Evita duplicação de código e torna o modelo mais organizado.
Proporciona modularidade e suporte ao polimorfismo.
Atualizações na classe base automaticamente refletem nas subclasses.

C - Exemplo de sobrescrita do método calcular_valor():

SeguroVeiculo: Implementa um cálculo genérico.
SeguroCarro: Sobrescreve para incluir taxa adicional caso o carro seja blindado e custos relacionados à idade do veículo.
SeguroMoto: Sobrescreve para adicionar taxas extras para motos de alta cilindrada.

### Exercício 5: Diagramas de Objetos UML

C - Explique a utilidade do diagrama:

O diagrama permite visualizar instâncias concretas do sistema, mostrando os dados e suas relações.
Auxilia na validação do modelo, garantindo que ele atende às necessidades dos usuários.

### Exercício 6: Abstração e Encapsulamento

A - Implemente as classes Cliente e Carro utilizando encapsulamento:

Proteja atributos como cpf e placa, tornando-os acessíveis apenas por meio de métodos públicos específicos.

B - Escreva uma função em pseudocódigo para verificar a validade da apólice na classe Seguro:
verificar_vigencia()
    data_atual = obter_data_atual()
    se data_atual estiver entre inicio_vigencia e fim_vigencia:
        retornar verdadeiro
    caso contrário:
        retornar falso

C - Importância do encapsulamento:

Protege informações sensíveis, como CPF e placa de veículos.
Reduz o risco de acessos indevidos e facilita a manutenção do sistema.
Garante que alterações nos atributos sejam controladas e realizadas de forma consistente.