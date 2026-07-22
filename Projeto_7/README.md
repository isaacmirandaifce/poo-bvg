# **Projeto Avaliativo 7: Métodos e Classes Genéricas - C++**

## **Objetivo**

Ampliar o sistema acadêmico existente com a introdução de métodos e classes genéricas, otimizando a manipulação de dados no sistema e reforçando conceitos importantes para o desenvolvimento de sistemas escaláveis e reutilizáveis. Este projeto busca aplicar conceitos fundamentais de generics de forma prática e contextualizada.

---

# 🎟️ Ticket #815: Motor Genérico de Filtragem e Processamento (C++ Templates)

**De:** Arquiteto de Software (Professor)

**Para:** Engenheiro de Dados C++ (Alunos)

**Projeto:** SecureBank Pro (Módulo de Data Analytics)

**Status:** `To Do` | **Prioridade:** `Alta`

## 📝 Contexto

Olá, equipe!
Atualmente, nosso sistema possui várias classes de filtro (`FiltroTransacao`, `FiltroLogAcesso`, `FiltroCliente`), todas fazendo exatamente a mesma coisa: iterando sobre um `vector` e aplicando regras condicionais (ex: "Filtrar transações acima de R$10.000" ou "Filtrar logs de erro críticos"). Isso viola o princípio DRY (*Don't Repeat Yourself*).

Sua missão nesta sprint é unificar essa lógica criando uma **Classe Genérica (Template Class)** chamada `DataFilter<T>`. Esse componente será o coração do nosso novo Pipeline de Dados e deverá ser capaz de armazenar, filtrar e executar ações sobre **qualquer** tipo de objeto que passarmos para ele.

---

## Critérios de Aceitação (Acceptance Criteria)

### 1. A Classe Genérica `DataFilter<T>`

Você deve criar uma classe baseada em `template <typename T>` que possua um container interno (`std::vector<T>`) para armazenar os dados. A classe deve implementar os seguintes métodos:

* **`adicionar(T elemento)`**: Adiciona um novo elemento ao pipeline.
* **`filtrar(std::function<bool(const T&)> condicao)`**: Recebe uma função (ou expressão lambda) como regra de negócio e retorna um novo `vector<T>` contendo apenas os elementos que passaram no teste.
* **`processar(std::function<void(const T&)> acao)`**: Recebe uma função que executa uma ação (ex: imprimir na tela, ou gravar em log) para cada elemento armazenado.

### 2. Integração e Testes (Classes de Domínio)

Para provar que sua classe genérica funciona com tipos diferentes, crie (ou reutilize) duas classes distintas no seu `main.cpp`:

* **Classe `Transacao**`: Contém `id`, `valor` e `tipo` ("PIX", "TED").
* **Classe `LogSeguranca**`: Contém `timestamp`, `nivel` ("INFO", "CRITICAL") e `mensagem`.

No `main.cpp`, você deverá instanciar dois filtros separados (`DataFilter<Transacao>` e `DataFilter<LogSeguranca>`), populá-los e aplicar expressões *lambda* para extrair transações suspeitas e logs críticos.

### 3. Diagrama UML

O diagrama de classes deve representar a classe template `DataFilter<T>` com a notação UML correta (uma caixa tracejada no canto superior direito da classe indicando o parâmetro de tipo `T`), além de mostrar sua relação de uso com as classes de domínio.

---

##  Estrutura de Arquivos Exigida 

Siga o padrão rigoroso do repositório. Preste atenção à dica do Tech Lead abaixo sobre a compilação de templates.

```text
Projeto_7/
│
├── docs/
│   └── Diagrama_DataFilter_UML.png  # Diagrama com a notação de Template
│
├── src/
│   ├── DataFilter.h                 # Declaração E implementação do Template (Ver Dica!)
│   ├── Transacao.h / .cpp           # Domínio 1
│   ├── LogSeguranca.h / .cpp        # Domínio 2
│   └── main.cpp                     # Instanciação dos templates e lambdas
│
└── README.md                        # Documentação rápida do componente

```

---

## Fluxo de Entrega e Regras Técnicas

1. **Desenvolvimento:** Crie a branch no seu Fork e implemente as classes. Inclua as bibliotecas `<functional>`, `<vector>` e `<algorithm>`.
2. **Uso de Lambdas:** No seu `main.cpp`, não crie funções soltas para passar para o filtro. Use expressões lambda modernas do C++ (ex: `[](const Transacao& t) { return t.getValor() > 5000; }`).
3. **Pull Request:** Submeta sua PR com o título: `Projeto_7 - [Seu Nome Completo]`.

---

## Rubrica de Avaliação (Code Review)

| Critério | Descrição | Pontuação |
| --- | --- | --- |
| **Classes Genéricas (Templates)** | A sintaxe `template <typename T>` foi utilizada corretamente? O código compila sem erros para tipos diferentes? | 3.5 pts |
| **Funções Funcionais (`std::function`)** | Os métodos de filtro e processamento utilizam ponteiros de função/lambdas adequadamente para injetar a regra de negócio? | 2.5 pts |
| **Aplicação de Domínio** | O `main.cpp` testa o filtro de forma coerente instanciando-o para as classes `Transacao` e `LogSeguranca`? | 2.0 pts |
| **Arquitetura e UML** | A notação UML de template está correta? O código está bem documentado e segue o padrão do repositório? | 2.0 pts |

> ⚠️ **Aviso Crítico do Tech Lead:** Em C++, as implementações de métodos de classes Template **não devem** ser separadas em um arquivo `.cpp` isolado, a menos que você faça a instanciação explícita. O compilador precisa ver a implementação inteira no momento em que a classe é usada. Portanto, para a `DataFilter<T>`, escreva a implementação dos métodos **dentro do próprio `DataFilter.h**` (ou use um arquivo `.hpp`). Sucesso na sprint!
