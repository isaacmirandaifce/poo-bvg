# Projeto 2 — Paradigma de Orientação a Objetos e UML

## InsureTech Pro — Subsistema de Cálculo de Prêmios e Sinistros

---

## Como o Polimorfismo resolveu o código legado

### O problema: código procedural com `if/else`

O código legado centralizava toda a lógica de cálculo em uma única função com
cadeias de `if/elif`, verificando o tipo do seguro por meio de Strings:

```python
def calcular_valor_seguro(tipo, base, detalhe):
    if tipo == "CARRO":
        ...
    elif tipo == "VIDA":
        ...
    elif tipo == "RESIDENCIAL":
        ...
```

**Problemas desta abordagem:**
- Viola o **Princípio Aberto/Fechado**: adicionar um novo tipo de seguro exige
  modificar a função existente, arriscando quebrar o que já funciona.
- Dificulta testes unitários: não dá para testar cada tipo de seguro isoladamente.
- Aumenta o acoplamento: a função precisa "conhecer" todos os tipos possíveis.

---

### A solução: Polimorfismo com Herança

A refatoração utilizou os pilares da Orientação a Objetos:

#### 1. Abstração e Herança
Uma classe base abstrata `Seguro` define a interface comum:

```python
class Seguro(ABC):
    @abstractmethod
    def calcular_premio(self) -> float:
        pass
```

Cada tipo de seguro herda de `Seguro` e implementa sua própria regra:

```python
class SeguroAuto(Seguro):
    def calcular_premio(self) -> float:
        return self._valor_base * (1.20 if self.__ano_fabricacao < 2010 else 1.05)

class SeguroVida(Seguro):
    def calcular_premio(self) -> float:
        return self._valor_base * (2.0 if self.__idade_segurado > 60 else 1.10)

class SeguroResidencial(Seguro):
    def calcular_premio(self) -> float:
        return self._valor_base * (1.15 if self.__tipo_imovel == "CASA" else 1.05)
```

#### 2. Polimorfismo em ação
O `main.py` percorre uma lista com tipos variados de seguros e chama
`calcular_premio()` — **sem nenhum `if/else`**:

```python
for seguro in lista_de_seguros:   # lista com SeguroAuto, SeguroVida, SeguroResidencial
    print(seguro.calcular_premio())  # cada objeto sabe como responder
```

#### 3. Encapsulamento
Dados sensíveis como CPF do cliente e placa do veículo são privados (`__atributo`)
e acessados apenas por métodos controlados (`get_cpf_mascarado()`, `get_placa()`).

#### 4. Extensibilidade
Para adicionar o Seguro de Viagem amanhã, basta:

```python
class SeguroViagem(Seguro):
    def calcular_premio(self) -> float:
        # nova regra de negócio
        ...
```

O `main.py` e todo o código existente continuam funcionando sem nenhuma alteração.
Isso é o **Princípio Aberto/Fechado** na prática.

---

## Estrutura do Projeto

```
Projeto_2/
├── docs/
│   └── diagrama_classes.png       # Diagrama UML exportado
├── src/
│   ├── models/
│   │   ├── cliente.py             # Entidade Cliente
│   │   └── seguros.py             # Hierarquia de herança
│   └── main.py                    # Demonstração do polimorfismo
└── README.md
```

---

## Como executar

```bash
# A partir da pasta Projeto_2/
python src/main.py
```

---

## Conceitos aplicados

| Conceito | Onde está aplicado |
|---|---|
| **Abstração** | Classe `Seguro(ABC)` com método `@abstractmethod` |
| **Herança** | `SeguroAuto`, `SeguroVida`, `SeguroResidencial` herdam de `Seguro` |
| **Polimorfismo** | `calcular_premio()` com comportamentos distintos por subclasse |
| **Encapsulamento** | Atributos `__privados` com getters controlados |
| **Associação** | `Seguro` possui referência a `Cliente` (titular) |
