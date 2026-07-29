# **Projeto Avaliativo 4: Modularização, Modificadores de Acesso e Funções Amigas - C++**

## **Objetivo**

Desenvolver um projeto prático em C++ que consolide os conhecimentos sobre modularização, modificadores de acesso (public, private, protected) e funções amigas. O tema escolhido terá utilidade prática para a vivência dos alunos de Análise e Desenvolvimento de Sistemas, reforçando conceitos fundamentais e sua aplicação no desenvolvimento de software.

---

# 🎟️ Ticket #704: Módulo de Auditoria de Transações Bancárias (C++)

**De:** CTO / Arquiteto de Segurança (Professor)

**Para:** Desenvolvedor Backend (Alunos)

**Projeto:** SecureBank Pro

**Status:** `To Do` | **Prioridade:** `Crítica`

##  Contexto

Olá, time! No setor bancário, a integridade dos dados é nossa maior prioridade. Atualmente, temos o desafio de permitir que um sistema externo de **Auditoria** verifique se uma transação financeira é legítima, sem que os detalhes sensíveis da conta do cliente fiquem expostos para o resto do sistema.

Nesta sprint, utilizaremos o conceito de **Funções Amigas (`friend`)** para dar permissão especial de acesso ao módulo de auditoria, e o modificador **`protected`** para organizar nossa hierarquia de contas, garantindo o encapsulamento exigido pelas normas bancárias.

---

##  Critérios de Aceitação 

### 1. Modularização e Encapsulamento

O projeto deve ser estritamente modularizado em arquivos `.h` e `.cpp`.

* **Classe `ContaBancaria`:** * `private`: `string titular` e `string cpf`.
* `protected`: `double saldo`. (O uso de `protected` permitirá que futuras subclasses de investimento acessem o saldo diretamente).
* `public`: Construtor e método para exibir dados básicos.


* **Classe `Transacao`:**
* Atributos privados: `double valor` e `string data`.



### 2. Funções Amigas 

Para validar se uma transação é segura (ex: o valor da transação não pode ser maior que o saldo atual), implemente uma **função amiga** chamada `validarTransacao`.

* Essa função **não** deve ser membro de nenhuma das classes.
* Ela deve receber como parâmetros um objeto `ContaBancaria` e um objeto `Transacao`.
* Por ser `friend`, ela terá permissão de ler o `saldo` (da conta) e o `valor` (da transação) para realizar a lógica de auditoria.

### 3. Implementação Técnica

* O arquivo `main.cpp` deve simular a criação de uma conta e uma tentativa de transação, chamando a função amiga para validar o processo.

---

##  Estrutura de Arquivos Exigida 

Respeitando o padrão de organização de código e as regras de envio de PRs do repositório:

```text
Projeto_4/
│
├── docs/
│   └── Diagrama_Auditoria_UML.png  # Diagrama com relações de amizade e visibilidade
│
├── src/
│   ├── ContaBancaria.h / .cpp      # Atributos private/protected
│   ├── Transacao.h / .cpp          # Atributos private e declaração da friend function
│   └── main.cpp                    # Orquestração do teste de auditoria
│
└── README.md                       # Explicação técnica de por que usar 'friend' neste caso

```

---

##  Fluxo de Entrega 

1. **Modelagem:** Crie o diagrama UML destacando os modificadores de acesso: `-` para privado, `#` para protegido e `+` para público.
2. **Desenvolvimento:** Siga as regras de indentação e nomenclatura do `CONTRIBUTING.md` do repositório.
3. **Pull Request:** Submeta sua PR com o título: `Projeto_4 - [Seu Nome Completo]`. Na descrição, justifique o uso do modificador `protected` na classe `ContaBancaria`.

---

##  Rubrica de Avaliação (Tech Lead Review)

| Critério | Descrição | Pontuação |
| --- | --- | --- |
| **Modularização** | Divisão correta entre headers e sources com guardas de inclusão? | 2.5 pts |
| **Modificadores de Acesso** | Uso correto de `private` para dados sensíveis e `protected` para o saldo? | 2.5 pts |
| **Função Amiga** | A função `validarTransacao` foi declarada como `friend` e acessa os membros privados sem usar getters? | 3.0 pts |
| **UML e Boas Práticas** | O diagrama representa fielmente a visibilidade dos atributos e a estrutura do código? | 2.0 pts |

> **Dica de Segurança:** Embora a `friend function` quebre o encapsulamento, ela é uma ferramenta poderosa para acoplar módulos de forma controlada. Use-a apenas quando um acesso externo "íntimo" for estritamente necessário para a lógica de negócio, como em auditorias ou sobrecarga de operadores.

## **Entrega**

1. **Formato:**
   - Carregue os arquivos no repositório da turma, na subpasta `/Projetos/Projeto_4`.
   - Inclua o diagrama UML no formato `png` ou `jpg`.

2. **Prazo:**
   - A entrega deve ser realizada em sete dias.
