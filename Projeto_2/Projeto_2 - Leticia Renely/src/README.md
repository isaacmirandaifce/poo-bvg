````md
# Projeto 2 — Paradigma de Orientação a Objetos e UML  
## InsureTech Pro — Subsistema de Cálculo de Prêmios e Sinistros

Este projeto foi desenvolvido com o objetivo de aplicar os conceitos fundamentais da **Programação Orientada a Objetos (POO)**, utilizando **Herança, Abstração, Encapsulamento e Polimorfismo**, além da modelagem arquitetural com **Diagrama de Classes UML**.

A proposta consistiu em refatorar um código legado responsável pelo cálculo de prêmios de seguros, eliminando estruturas condicionais extensas (`if/elif`) e substituindo-as por uma solução orientada a objetos, mais organizada, extensível e aderente às boas práticas de engenharia de software.

---

# Como o Polimorfismo resolveu o código legado

## O problema: código procedural com `if/else`

O sistema antigo centralizava toda a lógica de cálculo de seguros em uma única função:

```python
def calcular_valor_seguro(tipo, base, detalhe):
    if tipo == "CARRO":
        if detalhe < 2010:
            return base * 1.2
        return base * 1.05

    elif tipo == "VIDA":
        if detalhe > 60:
            return base * 2.0
        return base * 1.1

    elif tipo == "RESIDENCIAL":
        if detalhe == "CASA":
            return base * 1.15
        return base * 1.05

    else:
        return base
````

Embora funcional, essa abordagem apresenta vários problemas arquiteturais:

### Problemas identificados

* **Viola o princípio Aberto/Fechado (Open/Closed Principle):** cada novo tipo de seguro exige alterar a função existente.
* **Dificulta a manutenção:** toda regra de negócio fica concentrada em um único ponto.
* **Baixa escalabilidade:** quanto mais tipos de seguro forem adicionados, maior será a complexidade.
* **Alto acoplamento:** a função precisa conhecer todas as regras de todos os seguros.
* **Testabilidade reduzida:** não é possível testar cada seguro isoladamente.

---

# A solução: Polimorfismo com Herança

## 1. Abstração e Herança

Foi criada uma classe abstrata chamada `Seguro`, responsável por definir os atributos e comportamentos comuns entre todos os seguros:

```python
from abc import ABC, abstractmethod

class Seguro(ABC):
    def __init__(self, titular, valor_base):
        self._titular = titular
        self._valor_base = valor_base

    @abstractmethod
    def calcular_premio(self):
        pass
```

Essa classe representa o conceito genérico de seguro, enquanto cada tipo específico herda dela e implementa sua própria lógica.

---

## 2. Especialização das subclasses

Cada modalidade de seguro implementa sua regra própria de cálculo.

### SeguroAuto

```python
class SeguroAuto(Seguro):
    def __init__(self, titular, valor_base, ano):
        super().__init__(titular, valor_base)
        self.__ano = ano

    def calcular_premio(self):
        if self.__ano < 2010:
            return self._valor_base * 1.2
        return self._valor_base * 1.05
```

### SeguroVida

```python
class SeguroVida(Seguro):
    def __init__(self, titular, valor_base, idade):
        super().__init__(titular, valor_base)
        self.__idade = idade

    def calcular_premio(self):
        if self.__idade > 60:
            return self._valor_base * 2.0
        return self._valor_base * 1.1
```

### SeguroResidencial

```python
class SeguroResidencial(Seguro):
    def __init__(self, titular, valor_base, tipo_imovel):
        super().__init__(titular, valor_base)
        self.__tipo_imovel = tipo_imovel

    def calcular_premio(self):
        if self.__tipo_imovel.upper() == "CASA":
            return self._valor_base * 1.15
        return self._valor_base * 1.05
```

---

## 3. Polimorfismo em ação

No arquivo principal, o sistema trabalha com uma lista de seguros variados sem precisar verificar o tipo de cada um:

```python
seguros = [
    SeguroAuto(cliente1, 1000, 2008),
    SeguroVida(cliente2, 1500, 65),
    SeguroResidencial(cliente1, 2000, "CASA")
]

for seguro in seguros:
    print(seguro.calcular_premio())
```

O método chamado é o mesmo (`calcular_premio()`), mas o comportamento muda conforme o objeto.

Esse é o **polimorfismo**, permitindo que diferentes objetos respondam de forma diferente à mesma mensagem.

---

## 4. Encapsulamento

Os atributos sensíveis foram protegidos com encapsulamento:

```python
self.__cpf
self.__ano
self.__idade
```

Isso impede acesso direto indevido aos dados internos da classe.

---

## 5. Extensibilidade

Se amanhã for necessário adicionar um novo tipo de seguro, como `SeguroViagem`, basta criar uma nova subclasse:

```python
class SeguroViagem(Seguro):
    def calcular_premio(self):
        return self._valor_base * 1.30
```

Nenhuma modificação será necessária no código existente.

Isso garante aderência ao princípio:

> **Aberto para extensão, fechado para modificação**

---

# Estrutura do Projeto

```bash
Projeto_2/
│
├── docs/
│   └── diagrama_classes.png
│
├── src/
│   ├── models/
│   │   ├── cliente.py
│   │   └── seguros.py
│   │
│   └── main.py
│
└── README.md
```

---

# Descrição dos Arquivos

### `cliente.py`

Responsável pela entidade `Cliente`, armazenando os dados do segurado.

### `seguros.py`

Contém a classe abstrata `Seguro` e suas subclasses:

* `SeguroAuto`
* `SeguroVida`
* `SeguroResidencial`

### `main.py`

Demonstra o uso do polimorfismo, instanciando diferentes tipos de seguro e chamando `calcular_premio()`.

### `diagrama_classes.png`

Representação UML da arquitetura orientada a objetos do sistema.

---

# Como executar o projeto

Na pasta raiz do projeto, execute:

```bash
python src/main.py
```

Saída esperada:

```bash
Cliente: Laylla | Prêmio: R$ 1200.00
Cliente: José | Prêmio: R$ 3000.00
Cliente: Laylla | Prêmio: R$ 2300.00
```

---

# Conceitos aplicados

| Conceito           | Aplicação no projeto                                                |
| ------------------ | ------------------------------------------------------------------- |
| **Abstração**      | Classe `Seguro` abstrata define a interface comum                   |
| **Herança**        | `SeguroAuto`, `SeguroVida` e `SeguroResidencial` herdam de `Seguro` |
| **Polimorfismo**   | `calcular_premio()` é sobrescrito em cada subclasse                 |
| **Encapsulamento** | Atributos privados (`__atributo`) protegem dados internos           |
| **Associação**     | `Seguro` possui um `Cliente` como titular                           |

---

# Conclusão

A refatoração utilizando **Programação Orientada a Objetos** trouxe melhorias significativas em:

* **Organização do código**
* **Facilidade de manutenção**
* **Escalabilidade**
* **Legibilidade**
* **Extensibilidade**

O uso do **polimorfismo** eliminou a necessidade de estruturas condicionais extensas e tornou o sistema preparado para crescer de forma sustentável.

Com essa arquitetura, novas modalidades de seguro podem ser adicionadas com facilidade, sem alterar o funcionamento das partes já existentes do sistema.

```
```
