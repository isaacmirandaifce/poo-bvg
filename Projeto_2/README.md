# Projeto Avaliativo 2 - Paradigma de Orientação a Objetos e UML 

---

# Ticket #508: Subsistema de Cálculo de Prêmios e Sinistros

**De:** Tech Lead (Professor)
**Para:** Desenvolvedor Backend (Aluno)  
**Projeto:** InsureTech Pro  
**Status:** `To Do` | **Prioridade:** `Crítica`

## Contexto
Nossa equipe de negócios fechou novos contratos para seguros de **Vida** e **Residencial**, além do de **Automóveis** que já possuíamos. O problema é que o código atual que calcula o valor do seguro (prêmio) é um método gigantesco cheio de `if/else`, que verifica o tipo de seguro via Strings. Isso viola o princípio de "Aberto/Fechado" e está impossível de testar.

Além disso, precisamos documentar a arquitetura antes de codificar, para garantir que o **Gap Semântico** entre o negócio e o código seja reduzido.

###  O Código Legado:

```python
# Script legado que centraliza toda a lógica (Antipadrão)
def calcular_valor_seguro(tipo, base, detalhe):
    if tipo == "CARRO":
        # Se for carro, o detalhe é o ano
        if detalhe < 2010:
            return base * 1.2
        return base * 1.05
    elif tipo == "VIDA":
        # Se for vida, o detalhe é a idade
        if detalhe > 60:
            return base * 2.0
        return base * 1.1
    elif tipo == "RESIDENCIAL":
        # Se for residencial, o detalhe é se é apartamento ou casa
        if detalhe == "CASA":
            return base * 1.15
        return base * 1.05
    else:
        return base
```

---

## Critérios de Aceitação

### Fase 1: Modelagem Técnica (UML)
Antes de codificar, você deve entregar um **Diagrama de Classes UML** (pode ser feito em ferramentas como LucidChart, Draw.io ou Mermaid).
1.  **Herança:** Crie uma classe base abstrata `Seguro` e as subclasses `SeguroAuto`, `SeguroVida` e `SeguroResidencial`.
2.  **Atributos:** Identifique os atributos comuns (ex: `titular`, `valor_base`) e os específicos de cada subclasse.
3.  **Relacionamento:** Represente a associação entre `Cliente` e seus `Seguros`.

### Fase 2: Implementação
1.  **Polimorfismo:** Implemente o método `calcular_premio()` em cada classe. O sistema principal não deve saber *qual* seguro está calculando; ele apenas chama o método e o objeto responde com o valor correto.
2.  **Abstração:** A classe pai `Seguro` não deve permitir instâncias diretas (use o módulo `abc` do Python se souber, ou apenas defina o conceito).
3.  **Encapsulamento:** Mantenha os dados sensíveis (CPF do cliente, placa do carro) protegidos, conforme as boas práticas do repositório.

---

## Estrutura de Arquivos Exigida

Conforme o padrão do repositório `isaacmirandaifce/poo-bvg`, organize assim:

```text
Projeto_2/
│
├── docs/
│   └── diagrama_classes.png   # O diagrama UML exportado
│
├── src/
│   ├── models/
│   │   ├── cliente.py         # Entidade Cliente
│   │   └── seguros.py         # Hierarquia de Herança (Seguro, SeguroAuto, etc)
│   │
│   └── main.py                # Instancia diferentes seguros e mostra o polimorfismo
└── README.md                  # Explicação de como o polimorfismo resolveu o código legado
```

---

## Fluxo de Entrega (Git Workflow)

1. No seu fork local, crie a pasta `Projeto_2`.
2. Implemente a solução garantindo que o `main.py` crie uma lista de seguros variados e percorra essa lista chamando `.calcular_premio()` (demonstrando o Polimorfismo).
3. **Docstrings:** Use o padrão de documentação exigido para explicar cada método.
4. Abra a **Pull Request (PR)** com o título: `Projeto_2 - [Seu Nome Completo]`.

---

## Rubrica de Avaliação

| Critério | Descrição |
| :--- | :--- |
| **Diagrama UML** | O diagrama usa a simbologia correta para Herança (seta vazia) e Associação? Reflete o código? |
| **Uso de Herança** | A classe base concentra o código comum e as filhas apenas as especializações? |
| **Polimorfismo** | O cálculo do prêmio foi implementado de forma que o `main.py` não precise de `if/else` para saber o tipo de seguro? |
| **Organização** | Seguiu a estrutura de pastas e as diretrizes do `CONTRIBUTING.md`? |

---
> O polimorfismo é uma ferramenta que permite ao sistema crescer. Amanhã, se criarmos o "Seguro de Viagem", basta adicionar uma nova classe sem mexer no código que já funciona!

## Entrega

- **Formato**: A entrega deverá ser feita no repositório da turma no GitHub, na pasta `Projeto_2`, com os arquivos desenvolvidos e um código de teste.
- **Prazo de Entrega**: Sete dias
