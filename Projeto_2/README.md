# Projeto Avaliativo 2 - Paradigma de Orientação a Objetos e UML

## Descrição
Este projeto tem como objetivo modelar e implementar um sistema para gerenciamento de seguros de carros, utilizando conceitos de orientação a objetos e diagramas UML. A atividade abrange modelagem de domínio, detalhamento de atributos e métodos, relacionamentos entre classes, herança, encapsulamento e criação de diagramas UML de objetos.

---

## Exercícios

### Exercício 1: Modelagem de Domínio
- Criação de classes: `Carro`, `Cliente`, `Seguro`.
- Definição dos atributos principais.
- Representação das relações entre classes (associação/agregação).
- Justificativa dos tipos de relacionamento entre `Seguro` e `Carro` e entre `Seguro` e `Cliente`.

### Exercício 2: Detalhamento de Atributos e Métodos
- Inclusão de métodos básicos em cada classe para operações essenciais, como exibir informações e atualizar dados.
- Implementação básica em código das classes com os métodos listados.

### Exercício 3: Modelagem de Relacionamentos e Associações
- Atualização do modelo para permitir que um cliente tenha múltiplos carros segurados e múltiplos seguros.
- Justificativa do relacionamento entre `Seguro` e `Carro` (agregação ou composição).
- Explicação sobre a representação de clientes com múltiplos seguros.

### Exercício 4: Modelagem com Herança
- Introdução da classe base `SeguroVeiculo`.
- Criação das subclasses `SeguroCarro` e `SeguroMoto`.
- Benefícios da herança para representar diferentes tipos de seguro.
- Sobrescrita do método `calcular_valor()` para cálculos específicos em cada tipo de seguro.

### Exercício 5: Diagramas UML de Objetos
- Representação da relação entre um cliente específico, seu carro e o seguro correspondente.
- Inclusão dos valores dos atributos nos objetos.
- Demonstração de como o diagrama facilita a visualização do sistema para um caso real.

### Exercício 6: Abstração e Encapsulamento
- Uso de encapsulamento para proteger atributos sensíveis (`cpf` e `placa`).
- Métodos públicos para acesso controlado às informações.
- Função para verificar a validade da apólice considerando a vigência.
- Justificativa da importância do encapsulamento para segurança, privacidade e manutenção do sistema.

---

## Como rodar o código (Exercício 6 - exemplo em Python)

```python
# Exemplo de uso das classes com encapsulamento

cliente = Cliente("João Silva", "123.456.789-00")
carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
seguro = Seguro(carro, cliente, 1500.0, "01/01/2024", "01/01/2025")

cliente.exibir_informacoes()
carro.exibir_detalhes()
print("Seguro válido?", seguro.verificar_vigencia())
