# Projeto 7 — Motor Genérico de Filtragem e Processamento (C++ Templates)

**Ticket:** #815
**Módulo:** SecureBank Pro — Data Analytics
**Autor:** Breno

## 1. Objetivo

Eliminar a duplicação de lógica presente em `FiltroTransacao`, `FiltroLogAcesso` e
`FiltroCliente` — todas repetindo o mesmo padrão de "iterar um `vector` e aplicar
uma regra condicional" — através de uma única **classe genérica** `DataFilter<T>`,
capaz de armazenar, filtrar e processar qualquer tipo `T`.

## 2. Estrutura do Projeto

```
Projeto_7/
├── docs/
│   ├── diagrama.dot                     # Fonte Graphviz do diagrama
│   └── Diagrama_DataFilter_UML.png      # Diagrama de classes (notação de template)
├── src/
│   ├── DataFilter.h                     # Declaração + implementação do template
│   ├── Transacao.h / Transacao.cpp      # Domínio 1
│   ├── LogSeguranca.h / LogSeguranca.cpp# Domínio 2
│   └── main.cpp                         # Instanciação dos templates e lambdas
└── README.md
```

## 3. `DataFilter<T>` — decisões técnicas

### 3.1 Por que a implementação inteira vive no `.h`

Templates em C++ não geram código de fato até serem **instanciados** para um tipo
concreto (ex.: `DataFilter<Transacao>`). Essa instanciação acontece em tempo de
compilação, no arquivo que usa o template — no nosso caso, `main.cpp`. Se os
métodos de `DataFilter<T>` estivessem definidos em um `DataFilter.cpp` separado,
o compilador, ao compilar `main.cpp`, teria apenas a *declaração* da classe
disponível (via `#include "DataFilter.h"`) e nenhuma visão do corpo dos métodos
no momento de gerar o código para `T = Transacao` ou `T = LogSeguranca`. O
resultado seriam erros de *linkagem* (`undefined reference`).

Por isso, seguindo a recomendação do Tech Lead, toda a implementação de
`DataFilter<T>` (atributos, `adicionar`, `filtrar`, `processar`, `tamanho`) foi
escrita dentro da própria declaração da classe em `DataFilter.h`. A alternativa
correta (instanciação explícita em um `.cpp`) foi descartada de propósito: ela
fixaria `DataFilter` a uma lista pré-definida de tipos (`template class
DataFilter<Transacao>;`), o que contradiz o requisito do ticket de ter um
componente reutilizável para **qualquer** tipo de dado do pipeline.

### 3.2 `std::function` como mecanismo de injeção de regra de negócio

`filtrar` e `processar` não conhecem nenhuma regra de negócio própria — eles
recebem a regra de fora, como um `std::function<bool(const T&)>` (predicado de
filtro) ou `std::function<void(const T&)>` (ação a executar). Isso é o que
permite ao `main.cpp` reaproveitar a mesma classe `DataFilter<T>` tanto para
"transações acima de R$10.000" quanto para "logs de nível CRITICAL", sem que a
classe genérica precise saber o que é uma transação suspeita ou um log crítico.
Na prática, essa injeção é feita com **lambdas modernas do C++**, conforme
pedido no ticket (ex.: `[](const Transacao& t) { return t.getValor() >
10000.00; }`), evitando funções soltas.

`filtrar` usa `std::copy_if` (`<algorithm>`) para construir o vetor de
resultado, e `processar` itera com um `range-based for` aplicando a ação a cada
elemento — sem nunca modificar o `std::vector<T>` interno (os parâmetros de
callback e o laço usam `const T&`).

### 3.3 Aderência ao SOLID

- **DRY / Single Responsibility:** toda a lógica de "guardar + filtrar +
  processar uma coleção" está centralizada em `DataFilter<T>`; as classes de
  domínio (`Transacao`, `LogSeguranca`) só conhecem seus próprios dados.
- **Open/Closed:** novas regras de filtragem (ex.: "TED acima de R$20.000") ou
  novos tipos de domínio (ex.: `Cliente`, `LogAcesso`) podem ser suportados sem
  alterar uma única linha de `DataFilter.h` — basta escrever a lambda ou
  instanciar `DataFilter<NovoTipo>`.

## 4. Classes de domínio

| Classe | Atributos | Papel na demonstração |
|---|---|---|
| `Transacao` | `id`, `valor`, `tipo` (`"PIX"`/`"TED"`) | Testada com `DataFilter<Transacao>` |
| `LogSeguranca` | `timestamp`, `nivel` (`"INFO"`/`"CRITICAL"`), `mensagem` | Testada com `DataFilter<LogSeguranca>` |

`main.cpp` popula um `DataFilter<Transacao>` e um `DataFilter<LogSeguranca>`
independentes e aplica lambdas distintas em cada um, provando que a mesma
classe template atende aos dois domínios sem nenhuma alteração de código.

## 5. Diagrama UML

`docs/Diagrama_DataFilter_UML.png` (gerado com Graphviz a partir de
`docs/diagrama.dot`) representa `DataFilter<T>` com a caixa tracejada do
parâmetro de template `T` no canto superior direito da classe, além das
relações de *bind* (`T -> Transacao`, `T -> LogSeguranca`) e da instanciação
feita por `main.cpp`.

Para regerar o diagrama a partir da fonte:

```bash
neato -Tpng -Gdpi=150 docs/diagrama.dot -o docs/Diagrama_DataFilter_UML.png
```

## 6. Como compilar e executar

Compilado com flags estritas (sem nenhum warning ou erro):

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2 \
    -o projeto7 src/main.cpp src/Transacao.cpp src/LogSeguranca.cpp
./projeto7
```

## 7. Rubrica — como cada critério foi atendido

| Critério | Como foi atendido |
|---|---|
| Classes Genéricas (Templates) | `template <typename T> class DataFilter` compila sem erros para `Transacao` e `LogSeguranca`, com implementação completa em `DataFilter.h` |
| Funções Funcionais (`std::function`) | `filtrar` e `processar` recebem `std::function` e são sempre chamados com lambdas em `main.cpp` |
| Aplicação de Domínio | `main.cpp` instancia `DataFilter<Transacao>` e `DataFilter<LogSeguranca>`, populando e filtrando ambos de forma coerente com o domínio |
| Arquitetura e UML | Diagrama com notação de template (caixa tracejada de `T`), código comentado e organizado em `src/`/`docs/` conforme o padrão do repositório |
