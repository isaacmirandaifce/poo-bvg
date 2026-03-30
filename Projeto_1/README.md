# Projeto Avaliativo 1: Refatoração de Código Estruturado para Programação Orientada a Objetos

## Objetivo

Transformar um código estruturado em um código orientado a objetos, implementando uma classe que usa os princípios básicos de POO, tornando o código mais legível, modular, de fácil manutenção e escalável.

## Competências Avaliadas

- Entendimento dos conceitos de POO (Orientação a Objetos).
- Habilidade de refatorar elementos de um código estruturado para o formato orientado a objetos.
- Aplicação de conceitos de classe, atributos, métodos, encapsulamento e abstração.

---

#  Ticket #402: Refatoração do Sistema de Gestão de Clientes (Legado)

**De:** Tech Lead (Professor)  
**Para:** Equipe de Engenharia (Alunos)  
**Projeto:** Core Bancário  
**Status:** `To Do` | **Prioridade:** `Alta`

## Contexto
Olá, equipe! 
Nosso sistema atual de gerenciamento de clientes foi escrito anos atrás utilizando um paradigma procedural em Python. Com o crescimento da base de usuários, o código tornou-se um "código espaguete" (complexo, acoplado e difícil de manter). O sistema atual usa **listas paralelas e escopo global** para gerenciar o estado, o que está causando inconsistências graves, como clientes com saldo negativo e dificuldades de escalabilidade.

Sua atividade é atuar na **refatoração** desse código, migrando-o para a **Programação Orientada a Objetos (POO)**. 

### O Código Legado:
Este é o script atual que roda em produção. Vejam como os dados estão separados da lógica e dependem de variáveis globais:

```python
# Sistema Legado (Procedural com variáveis globais e listas paralelas)
nomes_clientes = []
idades_clientes = []
saldos_clientes = []
status_ativo = []
total_clientes = 0

def cadastrar_cliente(nome, idade, saldo_inicial):
    global total_clientes
    if total_clientes < 100:
        nomes_clientes.append(nome)
        idades_clientes.append(idade)
        saldos_clientes.append(saldo_inicial)
        status_ativo.append(True)
        total_clientes += 1
        print(f"Sucesso: Cliente {nome} cadastrado com ID {total_clientes - 1}")
    else:
        print("Erro Crítico: Limite de memória atingido.")

def movimentar_conta(id_cliente, valor, is_saque):
    if 0 <= id_cliente < total_clientes:
        if status_ativo[id_cliente]:
            if is_saque:
                # BUG EM PRODUÇÃO: Nenhuma validação de saldo negativo ocorre aqui!
                saldos_clientes[id_cliente] -= valor
                print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${saldos_clientes[id_cliente]:.2f}")
            else:
                saldos_clientes[id_cliente] += valor
                print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${saldos_clientes[id_cliente]:.2f}")
        else:
            print("Erro: Conta inativa.")
    else:
        print("Erro: Cliente não encontrado no sistema.")

def exibir_relatorio():
    print("--- RELATÓRIO GERAL ---")
    for i in range(total_clientes):
        print(f"ID: {i} | Nome: {nomes_clientes[i]} | Idade: {idades_clientes[i]} | Saldo: R${saldos_clientes[i]:.2f} | Ativo: {status_ativo[i]}")

if __name__ == "__main__":
    # Simulando o uso do sistema
    cadastrar_cliente("João Silva", 30, 1000.0)
    cadastrar_cliente("Maria Souza", 25, 500.0)
    
    # Operação perigosa que o sistema atual permite:
    movimentar_conta(0, 1500.0, True) # Deixa o João com saldo de -500.0!
    
    exibir_relatorio()
```

---

## Critérios de Aceitação

Para que sua **Pull Request (PR)** seja aprovada no *Code Review*, a refatoração deve cumprir:

1. **Fim das Listas Paralelas:** Criar uma classe `Cliente`. As informações do cliente devem pertencer ao objeto instanciado, eliminando o uso de `global` e listas separadas.
2. **Encapsulamento Restrito:** Todos os atributos (`nome`, `idade`, `saldo`, `status`) devem ser **privados** (utilizando o prefixo `__` em Python). O acesso de leitura deve ser feito via métodos *getters* ou *properties* (`@property`).
3. **Regra de Negócio:** O método responsável pelo saque **deve impedir saldo negativo**. Caso ocorra, a transação deve ser recusada e uma mensagem de erro (`ValueError` ou `print` amigável) deve ser gerada.
4. **Documentação:** O código deve conter **Docstrings** (`"""..."""`) nas classes e métodos detalhando suas responsabilidades, entradas e saídas.

---

## Estrutura de Arquivos Exigida

O repositório oficial da disciplina segue um padrão estrito. O seu projeto deverá ser organizado dentro da pasta `Projeto_1` com a seguinte árvore estrutural:

```text
Projeto_1/
│
├── src/               
│   ├── models/
│   │   └── cliente.py       # Modelagem da entidade (responsabilidade única)
│   │
│   └── main.py              # Script de inicialização (importa o cliente e testa)
│
├── docs/                    # (Opcional) Diagramas ou anotações
└── tests/                   # (Opcional para esta etapa)
```

---

## Como Entregar

A entrega simula o *Workflow* oficial da disciplina no repositório `isaacmirandaifce/poo-bvg`. Siga os passos:

1. Faça um **Fork** do repositório `isaacmirandaifce/poo-bvg` para a sua conta pessoal.
2. Clone o seu fork na sua máquina.
3. Crie os arquivos respeitando a estrutura de pastas indicada (`Projeto_1/src/...`).
4. Faça *commits* semânticos e organizados evidenciando seu progresso (Ex: `feat: cria classe Cliente`, `fix: valida saldo negativo`).
5. Realize o **Push** para o seu fork.
6. Abra uma **Pull Request (PR)** para o repositório original com os seguintes dados:
   * **Título da PR:** `Projeto_1 - [Seu Nome Completo]` *(Ex: Projeto_1 - João Silva)*.
   * **Descrição da PR:** Escreva um resumo evidenciando quais princípios de POO foram aplicados e como o bug do saldo negativo foi resolvido.

---

## Rubrica de Avaliação no Code Review

Sua PR será revisada e só será "Mergeada" (Aprovada) se cumprir a rubrica abaixo:

| Critério | Descrição 
| :--- | :--- |
| **Padrões de Código e Workflow** | A PR seguiu o padrão de nomenclatura? A pasta `Projeto_1` tem os arquivos `.py` nos locais corretos e documentação via Docstrings? 
| **Modelagem e Coesão** | O antipadrão de variáveis globais foi removido em favor da classe `Cliente` e do método construtor `__init__`? 
| **Encapsulamento** | Os atributos são estritamente privados (`__atributo`) e protegidos contra modificações indevidas no arquivo `main.py`? 
| **Lógica de Negócio** | O método de saque barra transações que resultariam em saldo negativo, protegendo o domínio? 

>  Lembrem-se que no arquivo `main.py` vocês precisarão importar a classe criada (`from models.cliente import Cliente`). Uma PR mal formatada ou um código sem encapsulamento será retornada com a tag *`changes requested`*. Mostrem que vocês dominam a teoria criando um código limpo e seguro. Boa sprint!

## Entrega

- **Prazo de Entrega**: Sete dias

