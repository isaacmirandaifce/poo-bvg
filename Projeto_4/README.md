# Projeto Avaliativo 4: Módulo de Auditoria de Transações Bancárias (SecureBank Pro)

Este repositório contém a implementação do **Projeto Avaliativo 4 / Ticket #704**, focado no desenvolvimento do sistema de segurança para auditoria de transações bancárias em C++.

O objetivo principal é demonstrar o uso controlado de **Funções Amigas (`friend`)**, **Modificadores de Acesso (`private`, `protected`, `public`)** e **Modularização em C++ (`.h` e `.cpp`)**.

---

## Estrutura do Repositório

```text
Projeto_4/
│
├── docs/
│   └── Diagrama_Auditoria_UML.png    # Diagrama de Classes e Relação de Amizade
│
├── src/
│   ├── ContaBancaria.h               # Interface da classe ContaBancaria
│   ├── ContaBancaria.cpp             # Implementação da classe ContaBancaria
│   ├── Transacao.h                   # Interface da classe Transacao e protótipo friend
│   ├── Transacao.cpp                 # Implementação da classe Transacao e função amiga
│   └── main.cpp                      # Orquestração do teste de auditoria
│
└── README.md                         # Documentação técnica do projeto


# Projeto 4 - Módulo de Auditoria de Transações Bancárias (C++)

## Descrição do Projeto
Este projeto implementa o módulo de auditoria do sistema **SecureBank Pro**. O objetivo principal é validar transações bancárias através de uma **Função Amiga (`friend`)**, mantendo o encapsulamento dos dados e utilizando o modificador **`protected`** para permitir a expansão da hierarquia de contas bancárias.

---

## Justificativa Técnica (Requisito do Ticket #704)

### 1. Por que usar `friend` (`validarTransacao`)?
A função de auditoria `validarTransacao` precisa avaliar se o valor da transação ultrapassa o saldo atual da conta. 

Em vez de expor o saldo publicamente via métodos `getter`, a declaração `friend` concede permissão pontual e restrita a essa função para ler os atributos privados (`valor`) e protegidos (`saldo`) sem quebrar o encapsulamento para o restante da aplicação.

### 2. Por que usar `protected` no `saldo`?
O atributo `saldo` da `ContaBancaria` foi definido como `protected` para que o saldo permaneça inacessível para chamadas externas (fora do escopo da classe), mas fique livremente acessível para futuras **subclasses** (como `ContaCorrente`, `ContaInvestimento` ou `ContaPoupanca`).

---

### Como Compilar e Executar

1. **Abra o terminal no diretório raiz do Projeto_4:**
   ```bash
   cd Projeto_4
   ```

2. **Compile todos os arquivos do módulo `src/` utilizando o `g++`:**
   ```bash
   g++ src/main.cpp src/ContaBancaria.cpp src/Transacao.cpp -o auditoria_app
   ```

3. **Execute o programa gerado:**

   * **Linux / macOS:**
     ```bash
     ./auditoria_app
     ```

   * **Windows:**
     ```cmd
     auditoria_app.exe
     ```
