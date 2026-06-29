# **Projeto Avaliativo 6: Classes Abstratas, Interfaces, Classes Enumeradas e Classes Internas**


# 🎟️ Ticket #602: Implementação do Core de Autenticação e Auditoria (IAM)

**De:** Diretor de Segurança da Informação / CISO (Professor)

**Para:** Engenheiro de Software Backend C++ (Alunos)

**Projeto:** SecureBank Pro (Módulo de Gestão de Identidades e Acessos)

**Status:** `To Do` | **Prioridade:** `Crítica (Compliance & Security)`

##  Contexto

Olá, time! Para estarmos em conformidade com as normas regulatórias de segurança financeira, precisamos de um sistema unificado que gerencie os perfis de acesso de nossos colaboradores e gere registros rígidos de auditoria.

O código antigo usava structs simples e não isolava dados sensíveis, violando regras básicas de conformidade. Sua tarefa nesta sprint é arquitetar a fundação do nosso ecossistema de segurança em C++, usando **Classes Abstratas** para forçar contratos de login, uma **Interface** para padronizar logs de auditoria, uma **Classe Enumerada** para definir permissões e uma **Classe Interna** altamente encapsulada para registrar as sessões de uso.

---

##  Critérios de Aceitação (Acceptance Criteria)

### 1. Contratos Globais (Classes Abstratas e Interfaces)

* **Classe Base `Usuario`:** Deve conter dados globais não sensíveis como `id` (int) e `username` (string).
* **Classe Abstrata `UsuarioAutenticavel`:** (Herda de `Usuario`). Esta classe **não deve** permitir instanciação direta por possuir um **Método Virtual Puro**: `virtual bool autenticar(std::string senha) = 0;`.
* **Interface `Relatorio`:** Uma classe puramente abstrata que atua como contrato operacional com o método virtual puro: `virtual void gerarRelatorio() const = 0;`.

### 2. Perfis de Acesso e Classes Concretas

Implemente três tipos de usuários que herdam de `UsuarioAutenticavel` e assinam a interface `Relatorio`:

1. **`UsuarioAdmin`:** Responsável pela TI. Deve sobrescrever o método de autenticação e implementar a geração de relatórios com logs de modificações do sistema.
2. **`UsuarioAuditor`:** Responsável por checar fraudes. Seu relatório exibe chaves de criptografia públicas e escopo de varredura.
3. **`UsuarioOperador`:** (Substituindo a classe Aluno). Representa o funcionário do caixa ou retaguarda.

### 3. Categorização por Classes Enumeradas (Enum Class)

* Crie uma `enum class TipoUsuario` contendo os identificadores de escopo: `ADMIN`, `AUDITOR`, `OPERADOR`. Cada classe concreta deve conter e expor seu tipo correspondente para triagem rápida no sistema de mensageria.

### 4. Isolamento Total por Classes Internas (Nested Classes)

Para evitar que dados confidenciais de navegação de um operador vazem na memória, você deve aplicar o conceito de **Classe Interna**:

* Dentro da classe `UsuarioOperador`, declare a classe interna privada `HistoricoAcessos` .
* A classe interna deve registrar de forma oculta uma lista com: `recursoAcessado` (string), `dataHora` (string) e `statusCodigo` (int).
* A classe externa (`UsuarioOperador`) gerenciará essa estrutura internamente, expondo os dados apenas no momento do disparo do método polimórfico `gerarRelatorio()`.

---

##  Estrutura de Arquivos Exigida (Projeto_6)

Seguindo a política de deploy modularizado da nossa equipe:

```text
Projeto_6/
│
├── docs/
│   └── Arquitetura_IAM_UML.png          # Diagrama UML com herança de interface e classe oculta
│
├── src/
│   ├── interfaces/
│   │   └── Relatorio.h                  # Definição do contrato da interface
│   │
│   ├── base/
│   │   └── UsuarioAutenticavel.h / .cpp # Classes abstratas base
│   │
│   ├── models/
│   │   ├── UsuarioAdmin.h / .cpp        # Implementação concreta Admin
│   │   ├── UsuarioAuditor.h / .cpp      # Implementação concreta Auditor
│   │   └── UsuarioOperador.h / .cpp     # Contém a classe interna HistoricoAcessos
│   │
│   └── main.cpp                         # Fluxo de simulação, login e loop polimórfico
└── README.md                            # Relatório de conformidade técnica e build

```

---

## Fluxo de Desenvolvimento e Git

1. **Arquitetura UML:** Documente o relacionamento. Indique a interface `Relatorio` com o estereótipo `<<interface>>` e a classe interna dentro do escopo visual de `UsuarioOperador`.
2. **Separação de Escopo:** Lembre-se de implementar os métodos da classe interna usando a resolução de escopo dupla no arquivo `.cpp`: `UsuarioOperador::HistoricoAcessos::Metodo()`.
3. **Simulação Polimórfica:** O `main.cpp` deve carregar um `std::vector<Relatorio*>` (ponteiros de interface), validar logins com senhas corretas/incorretas e percorrer o vetor executando `.gerarRelatorio()` em cascata para demonstrar a abstração.
4. Submeta a PR com o título: `Projeto_6 - [Seu Nome Completo]`.

---

## Rubrica de Avaliação (Tech Lead Review)

| Critério | Descrição | Pontuação |
| --- | --- | --- |
| **Abstração & Interfaces** | `UsuarioAutenticavel` e `Relatorio` foram criados como puramente virtuais? Impedem instanciação direta? | 3.0 pts |
| **Encapsulamento da Classe Interna** | A classe `HistoricoAcessos` está aninhada corretamente em `UsuarioOperador` e seus métodos de escopo respeitam as boas práticas de C++? | 3.0 pts |
| **Enumerações e Lógica** | Uso correto de `enum class` para categorizar relatórios no terminal, sem vulnerabilidades de vazamento de senhas? | 2.0 pts |
| **Enterprise Standard (UML/Pastas)** | Organização das pastas, divisão rigorosa de headers/sources e diagrama UML fiel? | 2.0 pts |

> Classes abstratas servem para definir comportamentos previsíveis. Se esquecerem de implementar o método `autenticar` em qualquer uma das três classes filhas, o compilador do C++ acusará erro e a build quebrará imediatamente.
