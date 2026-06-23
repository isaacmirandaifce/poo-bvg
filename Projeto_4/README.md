# Projeto 4: Módulo de Auditoria - SecureBank Pro 

**Ticket:** #704  
**Projeto:** SecureBank Pro  
**Autor:** Leícia Silva

---

## Sobre o Projeto

Este projeto consolida os conhecimentos sobre **modularização**, **modificadores de acesso** e **funções amigas** em C++. O sistema simula um módulo de auditoria bancária onde uma entidade externa precisa validar a legitimidade de transações financeiras sem comprometer o encapsulamento dos dados sensíveis dos clientes.

---

## Estrutura de Arquivos

A organização do código obedece aos padrões exigidos pelo repositório, separando as definições (`.h`) das implementações (`.cpp`):

```text
Projeto_4/
│
├── docs/
│   └── Diagrama_Auditoria_UML.png  # Diagrama UML com as relações de amizade
│
├── src/
│   ├── ContaBancaria.h             # Declaração da classe ContaBancaria
│   ├── ContaBancaria.cpp           # Implementação dos métodos da conta
│   ├── Transacao.h                 # Declaração da classe Transacao
│   ├── Transacao.cpp               # Implementação dos métodos da transação
│   └── main.cpp                    # Arquivo principal (Testes de auditoria)
│
└── README.md                       # Documentação e justificativas de arquitetura

```

---

## Como compilar o projeto
1. **Compilar:**

```bash
g++ src/main.cpp src/ContaBancaria.cpp src/Transacao.cpp -o auditoria_app
```

2. **Executar:**
- Windows:

```bash
.\auditoria_app.exe
```

- Linux:

```bash
./auditoria_app
```
--- 

## Justificativas de Arquitetura e Boas Práticas
1. Por que usar protected na classe ContaBancaria?
O atributo `saldo` foi definido como `protected` em vez de `private` para permitir a futura escalabilidade do sistema. No contexto bancário, é altamente provável que sejam criadas subclasses como ContaPoupanca ou ContaCorrente. Com o uso do protected, essas subclasses herdarão a capacidade de acessar e modificar o saldo diretamente, sem a necessidade de expor o atributo publicamente através de getters e setters, mantendo-o oculto do resto do sistema. O titular e o cpf, por outro lado, permanecem rigorosamente private.

2. Por que usar a função amiga (friend)?
A função `validarTransacao` representa um módulo externo de auditoria. Ela precisa acessar o `saldo` (da conta) e o `valor` (da transação) para garantir que a transação não exceda o dinheiro disponível.

Em vez de criar métodos públicos para retornar esses dados sensíveis — o que quebraria a segurança da conta, permitindo que qualquer parte do código visualizasse o saldo livremente —, optamos por declarar a função como `friend`.

Isso aplica o Princípio do Menor Privilégio: o encapsulamento geral das classes é mantido intacto e fechado, mas concedemos uma permissão de acesso exclusiva e restrita apenas à função de auditoria, permitindo que as regras de negócio sejam validadas de forma segura.

---