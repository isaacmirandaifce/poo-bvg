# Projeto Avaliativo 4: Módulo de Auditoria de Transações (C++)

Este projeto implementa um sistema de auditoria bancária segura em C++, focando em modularização, encapsulamento e o uso de funções amigas (`friend`) para controle de acesso restrito entre módulos.

## Estrutura do Projeto
- `docs/`: Contém o diagrama de classes UML.
- `src/`: Contém os códigos-fonte (`ContaBancaria.h/.cpp`, `Transacao.h/.cpp`, `main.cpp`).

## Justificativa Técnica: Por que usar `friend`?
O modificador `friend` foi utilizado para permitir que a função `validarTransacao` tenha acesso direto aos membros `protected` (saldo) da classe `ContaBancaria` e `private` (valor) da classe `Transacao`. 

Esta escolha técnica foi feita para:
1. **Auditoria de Alta Performance**: Evitar a criação de *getters* públicos que poderiam expor dados sensíveis desnecessariamente para todo o restante do sistema.
2. **Encapsulamento**: Manter os dados protegidos dentro de seus respectivos escopos, concedendo "permissão de leitura" apenas para a lógica específica de auditoria.

## Como compilar
Utilize o GCC a partir da pasta `Projeto_4/`:

```bash
g++ src/main.cpp src/ContaBancaria.cpp src/Transacao.cpp -o auditoria_app
