# Projeto 6 — SecureBank Pro: Core de Autenticação e Auditoria (IAM)

**Ticket:** #602 · **Prioridade:** Crítica (Compliance & Security)
**Módulo:** Gestão de Identidades e Acessos

## 1. Objetivo

Substituir o modelo antigo baseado em `struct` (sem isolamento de dados
sensíveis) por uma arquitetura orientada a objetos que utiliza **Classes
Abstratas**, **Interfaces**, **Classes Enumeradas (`enum class`)** e
**Classes Internas (nested classes)**, atendendo às normas de
conformidade de segurança financeira.

## 2. Arquitetura

```
Projeto_6/
│
├── docs/
│   ├── Arquitetura_IAM_UML.png   # Diagrama UML (herança + interface + classe aninhada)
│   └── Arquitetura_IAM_UML.dot   # Fonte editável do diagrama (Graphviz)
│
├── src/
│   ├── interfaces/
│   │   └── Relatorio.h                  # <<interface>> gerarRelatorio()
│   │
│   ├── enums/
│   │   └── TipoUsuario.h                # enum class ADMIN/AUDITOR/OPERADOR
│   │
│   ├── base/
│   │   ├── Usuario.h                    # Classe base (id, username)
│   │   ├── UsuarioAutenticavel.h/.cpp   # Classe abstrata (autenticar = 0)
│   │
│   ├── models/
│   │   ├── UsuarioAdmin.h/.cpp          # Perfil TI
│   │   ├── UsuarioAuditor.h/.cpp        # Perfil fraudes
│   │   └── UsuarioOperador.h/.cpp       # Perfil caixa/retaguarda + classe interna HistoricoAcessos
│   │
│   └── main.cpp                         # Login + loop polimórfico via vector<Relatorio*>
│
└── README.md
```

## 3. Decisões técnicas por critério da rubrica

### 3.1 Abstração & Interfaces (3.0 pts)

- `UsuarioAutenticavel` herda de `Usuario` e declara
  `virtual bool autenticar(std::string senha) = 0;` — um **método
  virtual puro**. Isso torna a classe abstrata: qualquer tentativa de
  `UsuarioAutenticavel obj(...)` gera erro de compilação
  (`cannot declare variable ... to be of abstract type`).
- `Relatorio` é uma interface pura: só possui `virtual void
  gerarRelatorio() const = 0;` e um destrutor virtual (nenhum dado,
  nenhuma implementação concreta).
- As três classes filhas (`UsuarioAdmin`, `UsuarioAuditor`,
  `UsuarioOperador`) herdam de `UsuarioAutenticavel` **e** assinam
  `Relatorio` via herança múltipla, implementando obrigatoriamente
  `autenticar()` e `gerarRelatorio()`. Se qualquer uma esquecer de
  implementar `autenticar`, o compilador recusa a build (testado
  manualmente durante o desenvolvimento).

### 3.2 Encapsulamento da Classe Interna (3.0 pts)

- `HistoricoAcessos` é declarada como classe **privada e aninhada**
  dentro de `UsuarioOperador` (`src/models/UsuarioOperador.h`).
- Todos os seus atributos (`recursoAcessado`, `dataHora`,
  `statusCodigo`) são privados; só existem getters, sem setters —
  os registros são imutáveis após criados.
- A implementação em `.cpp` usa **resolução de escopo dupla**, exatamente
  como pedido no ticket:
  ```cpp
  UsuarioOperador::HistoricoAcessos::HistoricoAcessos(...) { ... }
  UsuarioOperador::HistoricoAcessos::getRecursoAcessado() const { ... }
  ```
- `UsuarioOperador` mantém `std::vector<HistoricoAcessos> historico`
  como membro **privado**. Não existe getter que devolva o vetor
  inteiro — o único ponto de escrita é `registrarAcesso(...)` e o
  único ponto de leitura é o próprio `gerarRelatorio()`, que formata e
  imprime os dados. Código externo a `UsuarioOperador` não consegue
  sequer nomear o tipo `HistoricoAcessos` (é privado), muito menos
  instanciá-lo.

### 3.3 Enumerações e Lógica (2.0 pts)

- `enum class TipoUsuario { ADMIN, AUDITOR, OPERADOR };` evita
  conversão implícita para `int` e colisão de nomes (diferente de um
  `enum` tradicional).
- Cada classe concreta guarda um `tipo` estático correspondente e
  expõe via `getTipo()`, usado no `main.cpp` para a triagem rápida no
  sistema de mensageria (seção "Triagem por TipoUsuario").
- **Sem vazamento de senha:** a senha em texto puro nunca é mantida
  como estado do objeto. `UsuarioAutenticavel` armazena apenas
  `senhaHash` (gerado com `std::hash`), e `autenticar()` compara
  hashes, nunca strings de senha em claro. Nenhum `gerarRelatorio()`
  imprime senha ou hash.

### 3.4 Enterprise Standard — UML/Pastas (2.0 pts)

- Estrutura de pastas segue exatamente `interfaces/`, `base/`,
  `models/`, `docs/`, com separação rigorosa de `.h` (contratos) e
  `.cpp` (implementação).
- `docs/Arquitetura_IAM_UML.png` mostra: `Relatorio` com estereótipo
  `<<interface>>`, `UsuarioAutenticavel` com `<<abstract>>`,
  `TipoUsuario` como `<<enumeration>>` e `HistoricoAcessos` destacada
  visualmente dentro do escopo de `UsuarioOperador`
  (retângulo tracejado "Escopo visual: UsuarioOperador").

## 4. Fluxo do `main.cpp`

1. Instancia um `UsuarioAdmin`, um `UsuarioAuditor` e um
   `UsuarioOperador`.
2. Testa `autenticar()` com senha **correta** e **incorreta** para os
   três perfis.
3. Monta um `std::vector<Relatorio*>` apontando para os três objetos
   (usando **ponteiros de interface**) e percorre o vetor chamando
   `.gerarRelatorio()` em cascata — demonstração de polimorfismo puro:
   o `main.cpp` não sabe (nem precisa saber) o tipo concreto por trás
   de cada ponteiro.
4. Imprime a triagem por `TipoUsuario` de cada usuário.

