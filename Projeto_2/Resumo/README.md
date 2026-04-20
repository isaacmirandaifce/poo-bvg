# Projeto Avaliativo 2 — Paradigma de Orientação a Objetos e UML

Sistema de gerenciamento de seguros de veículos desenvolvido em Python,
com modelagem UML completa.

---

## Estrutura do Projeto

```
Projeto_2/
│
├── diagramas/
│   ├── exercicio1.png   — Classes e relacionamentos básicos
│   ├── exercicio2.png   — Classes com atributos e métodos
│   ├── exercicio3.png   — Múltiplos carros por seguro (agregação)
│   ├── exercicio4.png   — Hierarquia de herança
│   ├── exercicio5.png   — Diagrama de objetos com dados reais
│   └── exercicio6.png   — Encapsulamento e verificação de vigência
│
├── codigo/
│   ├── classes.py       — Todas as classes do sistema
│   └── teste.py         — Testes de todos os exercícios
│
└── README.md
```

---

## Como Executar

```bash
cd codigo
python teste.py
```

Requisitos: Python 3.10+. Sem dependências externas.

---

## Classes Implementadas

| Classe | Descrição |
|---|---|
| `Modelo` | Nome do modelo do veículo |
| `Carro` | Veículo com placa privada (encapsulamento) |
| `Cliente` | Cliente com CPF privado (encapsulamento) |
| `SeguroVeiculo` | Classe base abstrata para seguros |
| `Seguro` | Seguro geral, aceita múltiplos carros |
| `SeguroCarro` | Herda de `SeguroVeiculo`, adiciona franquia e cobertura a terceiros |
| `SeguroMoto` | Herda de `SeguroVeiculo`, adiciona cilindradas e capacete |

---

## Resumo das Respostas por Exercício

### Exercício 1
- **Modelo → Carro**: associação simples (Carro possui um Modelo).
- **Seguro ↔ Carro**: agregação — o Carro existe independentemente do Seguro.
- **Seguro ↔ Cliente**: associação simples — o Cliente existe antes e depois do Seguro.

### Exercício 2
Métodos implementados em `classes.py`:
- `Carro.exibir_detalhes()`, `Carro.atualizar_cor(nova_cor)`
- `Cliente.exibir_informacoes()`
- `Seguro.calcular_valor(base, taxa)`, `Seguro.verificar_vigencia()`

### Exercício 3
- `Seguro` possui uma lista `_carros: list[Carro]`, permitindo múltiplos carros.
- O relacionamento é **agregação**: o Carro existe fora do Seguro.
- Um `Cliente` pode ser referenciado por vários objetos `Seguro` distintos.

### Exercício 4
- `SeguroVeiculo` é a classe base com atributos e métodos comuns.
- `SeguroCarro` e `SeguroMoto` herdam e sobrescrevem `calcular_valor()`.
- **Benefício**: evita repetição de código (DRY) e permite polimorfismo.

### Exercício 5
Dados usados: João Silva, CPF 123.456.789-00, Toyota Corolla 2020,
Placa XYZ-1234, Seguro R$ 1.500,00 vigente de 01/01/2024 a 01/01/2025.

### Exercício 6
- `__cpf` e `__placa` são privados (name mangling em Python).
- Acesso externo somente via `get_cpf()` e `get_placa()`.
- CPF é retornado mascarado; acesso direto lança `AttributeError`.
- **Importância**: protege dados sensíveis, centraliza o controle de acesso
  e facilita auditoria sem alterar o restante do sistema.

---

## Pseudocódigo — verificar_vigencia()

```
função verificar_vigencia(seguro):
    hoje ← data_atual()
    se vigencia_inicio ≤ hoje E hoje ≤ vigencia_fim:
        retornar VERDADEIRO
    senão:
        retornar FALSO
```
