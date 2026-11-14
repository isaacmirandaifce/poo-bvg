# Projeto Avaliativo 2 — Polimorfismo e UML (Ticket #508)

Subsistema de cálculo de prêmios do **InsureTech Pro**: seguros de **Auto**, **Vida** e **Residencial**.

## Estrutura

```text
Projeto_02/
├── docs/
│   ├── diagrama_classes.png    # Diagrama UML exportado
├── src/
│   ├── models/
│   │   ├── cliente.py          # Entidade Cliente
│   │   └── seguros.py          # Seguro (abstrata), SeguroAuto, SeguroVida, SeguroResidencial
│   └── main.py                 # Demonstra o polimorfismo
└── README.md
```

## Como executar

A partir da pasta `Projeto_02`:

```bash
python src/main.py                          # demonstração
python -m unittest discover -s tests -v     # testes
```

## Como o polimorfismo resolveu o código legado

O código legado tinha uma função única, `calcular_valor_seguro(tipo, base, detalhe)`, com `if/else` sobre strings
(`"CARRO"`, `"VIDA"`, `"RESIDENCIAL"`). Problemas: o parâmetro `detalhe` mudava de significado conforme o tipo
(ano, idade ou "CASA"/"APARTAMENTO"), qualquer novo seguro exigia **editar** a função (violando o princípio
Aberto/Fechado) e era difícil testar cada regra isoladamente.

Na nova solução:

- **Herança e abstração:** `Seguro` é uma classe abstrata (`abc.ABC`) que guarda o que é comum (`titular`,
  `valor_base`) e declara o método abstrato `calcular_premio()`. Ela não pode ser instanciada diretamente.
- **Polimorfismo:** `SeguroAuto`, `SeguroVida` e `SeguroResidencial` implementam `calcular_premio()` com a sua
  própria regra e com atributos específicos (`ano`, `idade`, `tipo_imovel`), que agora têm nome e significado claros.
  O `main.py` percorre uma lista de seguros e chama `.calcular_premio()` **sem nenhum `if/else`**.
- **Aberto/Fechado:** para criar um "Seguro de Viagem", basta uma nova subclasse de `Seguro`; nada do que já
  funciona é alterado.
- **Associação:** um `Cliente` possui `0..*` seguros (`adicionar_seguro`, `seguros`, `calcular_total_premios`), e
  cada seguro tem um único titular. O cliente também usa polimorfismo ao somar os prêmios.
- **Encapsulamento:** o CPF do cliente (`__cpf`) e a placa do carro (`__placa`) são atributos privados e só são
  exibidos mascarados (`cpf_mascarado`, `placa_mascarada`).
- **Testabilidade:** cada regra é testada isoladamente em `tests/test_seguros.py`.

### Regras de prêmio (mantidas do legado)

| Seguro | Condição | Fator |
| :--- | :--- | :--- |
| Auto | ano < 2010 / demais | 1,20 / 1,05 |
| Vida | idade > 60 / demais | 2,00 / 1,10 |
| Residencial | casa / apartamento | 1,15 / 1,05 |