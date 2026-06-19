Projeto_4 — Módulo de Auditoria de Transações Bancárias
Disciplina: Análise e Desenvolvimento de Sistemas — IFCE  
Projeto: SecureBank Pro  
Ticket: #704
---
Descrição
Este projeto implementa um módulo de auditoria bancária em C++ que demonstra o uso de:
Modularização — separação em arquivos `.h` e `.cpp`
Modificadores de acesso — `private`, `protected` e `public`
Função amiga (`friend`) — para acesso controlado entre módulos
---
Estrutura de Arquivos
```
Projeto_4/
├── docs/
│   └── Diagrama_Auditoria_UML.svg   # Diagrama UML com visibilidade e amizade
├── src/
│   ├── ContaBancaria.h / .cpp        # Classe com atributos private/protected
│   ├── Transacao.h / .cpp            # Classe com atributos private + def. da friend
│   └── main.cpp                      # Simulação dos cenários de auditoria
└── README.md
```
---
Como Compilar e Executar
```bash
g++ -std=c++17 -Wall -Wextra -o securebank src/ContaBancaria.cpp src/Transacao.cpp src/main.cpp
./securebank
```
---
Justificativa do uso de `protected` em `ContaBancaria`
O atributo `saldo` foi declarado como `protected` — e não `private` — por uma razão arquitetural deliberada:
> **Em um sistema bancário real, existem subclasses especializadas de conta** (ex.: `ContaCorrente`, `ContaPoupanca`, `ContaInvestimento`) que precisam acessar e manipular o saldo diretamente em suas implementações internas — como ao aplicar rendimentos, calcular IOF ou aplicar tarifas —, sem precisar passar por um getter público, que exporia essa operação a qualquer parte do sistema.
O modificador `protected` estabelece um contrato de herança controlado: somente a própria classe e suas subclasses legítimas acessam `saldo` diretamente; o restante do sistema permanece isolado pelo encapsulamento.
Usar `private` tornaria necessário um getter público (`getSaldo()`), o que quebraria o encapsulamento para toda a aplicação. Usar `public` exporia o dado sensível sem qualquer controle. O `protected` é o ponto de equilíbrio correto para hierarquias de classes que compartilham responsabilidades internas.
---
Justificativa do uso de `friend`
A função `validarTransacao` precisa acessar simultaneamente:
`saldo` (membro `protected` de `ContaBancaria`)
`valor` (membro `private` de `Transacao`)
Esses membros não possuem getters públicos, pois expô-los violaria as normas de segurança bancária. A declaração `friend` concede acesso pontual e explícito apenas a essa função de auditoria, sem abrir a interface pública das classes. É o padrão correto quando um módulo externo precisa de "visão íntima" dos dados para realizar uma validação crítica de negócio.
---
Cenários Simulados
Cenário	Valor	Saldo	Resultado
1 — Transação dentro do limite	R$ 800,00	R$ 1.500,00	✅ Aprovada
2 — Valor acima do saldo	R$ 2.000,00	R$ 1.500,00	❌ Rejeitada
3 — Valor inválido (negativo)	R$ -50,00	R$ 1.500,00	❌ Rejeitada
