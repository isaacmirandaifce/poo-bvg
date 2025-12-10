# Projeto 6 — Sistema Avançado de Gestão Acadêmica

Descrição:

Este diretório contém uma implementação em C++ de um sistema acadêmico que demonstra o uso de:

- Classes abstratas (`UsuarioAutenticavel`);
- Interface (`Relatorio`);
- Enumeração (`TipoUsuario`);
- Classe interna (a classe `HistoricoDisciplinar` dentro de `Aluno`).

Funcionalidades principais:

- Autenticação simples por senha (senha armazenada como hash usando `std::hash`).
- Geração de relatórios por tipo de usuário via a interface `Relatorio`.
- Histórico disciplinar encapsulado na classe interna de `Aluno`.

Arquivos principais (em `Projeto_6/src`):

- `TipoUsuario.h` — enumeração dos tipos de usuário.
- `Relatorio.h` — interface com `gerarRelatorio()`.
- `Usuario.h` / `Usuario.cpp` — classe base comum.
- `UsuarioAutenticavel.h` / `UsuarioAutenticavel.cpp` — classe abstrata para usuários autenticáveis.
- `Disciplina.h` / `Disciplina.cpp` — modelo de disciplina (nota, carga horária).
- `Aluno.h` / `Aluno.cpp` — implementa `UsuarioAutenticavel` + `Relatorio`, contém `HistoricoDisciplinar`.
- `Professor.h` / `Professor.cpp` — implementa `UsuarioAutenticavel` + `Relatorio`.
- `FuncionarioAdministrativo.h` / `FuncionarioAdministrativo.cpp` — idem.
- `main.cpp` — exemplo demonstrativo (cria usuários, seta senhas, autentica e imprime relatórios).

Como compilar (Linux, g++):

Abra um terminal na raiz do repositório e execute:

```bash
mkdir -p Projeto_6/bin
g++ -std=c++17 -IProjeto_6/src Projeto_6/src/*.cpp -o Projeto_6/bin/projeto6
```

Como executar:

```bash
./Projeto_6/bin/projeto6
```

Saída esperada (resumo):

- Mensagens de autenticação (OK / Falha).
- Relatórios impressos para `Aluno`, `Professor` e `Funcionario` com informações relevantes e histórico.

Observações de segurança e implementação:

- Para simplicidade o hashing usa `std::hash` (não é seguro para uso em produção). Para um projeto real, usar um algoritmo de hash adequado (bcrypt, Argon2) e salting.
- Senhas não são persistidas em disco nesta implementação — apenas mantidas em memória como hash.
