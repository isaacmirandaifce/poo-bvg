# Projeto 4 — Sistema Bancário: Módulo de Auditoria

Módulo de auditoria bancária desenvolvido em C++ utilizando **funções amigas (`friend`)** e o modificador **`protected`**, garantindo encapsulamento seguro enquanto permite acesso controlado ao módulo de validação.

## Por que usar `friend` neste caso?

O problema central é: o módulo de auditoria precisa acessar dados sensíveis (`saldo` da conta e `valor` da transação) para validar se uma operação é legítima — mas esses dados não podem ser públicos para o resto do sistema.

A `friend function` resolve isso de forma cirúrgica:

- **Sem `friend`**: seria necessário tornar `saldo` e `valor` públicos (viola o encapsulamento) ou criar getters (expõe os dados para todo o sistema).
- **Com `friend`**: apenas a função `validarTransacao` recebe permissão especial de acesso, sem abrir os atributos para ninguém mais. É como dar uma chave específica para um auditor, sem mudar a fechadura da porta.

## Por que `protected` no saldo?

O `saldo` é `protected` (e não `private`) para permitir que **subclasses futuras** (ex: `ContaInvestimento`, `ContaPoupanca`) acessem o saldo diretamente sem precisar de getters — seguindo o princípio de herança do C++.

## Estrutura de Arquivos

```
Projeto_4/
├── docs/
│   └── Diagrama_Auditoria_UML.png
├── src/
│   ├── ContaBancaria.h / .cpp
│   ├── Transacao.h / .cpp
│   ├── validarTransacao.cpp
│   └── main.cpp
└── README.md
```

## Como Compilar

```bash
g++ src/main.cpp src/ContaBancaria.cpp src/Transacao.cpp src/validarTransacao.cpp -o auditoria_app
```

## Executar

```bash
./auditoria_app
```

## Saída Esperada

```
======================================
   Sistema Bancario — Modulo Auditoria
======================================

[ Dados da Conta ]
Titular: Ana Paula Souza
CPF:     123.456.789-00
Saldo:   R$ 1500

[ Tentativa de Transacao #1 ]
Valor:  R$ 800
Data:   17/05/2026
[AUDITORIA] Iniciando validacao da transacao...
[AUDITORIA] Saldo disponivel: R$ 1500
[AUDITORIA] Valor solicitado: R$ 800
[AUDITORIA] APROVADA — transacao legitima.

[ Tentativa de Transacao #2 ]
Valor:  R$ 2000
Data:   17/05/2026
[AUDITORIA] NEGADA — saldo insuficiente.

[ Tentativa de Transacao #3 ]
Valor:  R$ -50
Data:   17/05/2026
[AUDITORIA] NEGADA — valor invalido.
```