# Projeto 7 — Sistema Genérico de Filtragem e Relatórios Acadêmicos

Descrição curta
- Este projeto implementa uma classe genérica `Filtro<T>` (template) para filtrar, ordenar e aplicar ações sobre coleções de objetos do sistema acadêmico (por exemplo, `Aluno` e `Professor`). O código foi adaptado a partir do `Projeto_6` para deixar `Projeto_7` autocontido e demonstrar os requisitos do enunciado.

Funcionalidades implementadas
- **Filtro genérico:** `Filtro<T>` com `adicionarElemento`, `filtrarPorCondicao`, `imprimirTodos` e `ordenarPor`.
- **Exemplos:** filtragem de alunos por média (> 7.0), listagem de professores por disciplina, listagem de disciplinas cursadas por aluno em um ano, ordenação genérica.
- **Arquitetura:** classes `Aluno`, `Professor`, `Disciplina`, `Usuario`, `UsuarioAutenticavel`, `Relatorio` e `TipoUsuario` organizadas em `src/`.

Estrutura (principais arquivos)
- `src/Filtro.h` : classe template genérica para filtragem/ordenação
- `src/main.cpp` : programa demonstrativo que usa `Filtro` e as classes do domínio
- `src/Aluno.h` / `src/Aluno.cpp`
- `src/Professor.h` / `src/Professor.cpp`
- `src/Disciplina.h` / `src/Disciplina.cpp`
- `src/Usuario*.h/.cpp`, `src/Relatorio.h`, `src/TipoUsuario.h`

Como compilar
1. Abra um terminal na raiz do repositório (onde está a pasta `Projeto_7`).
2. Execute os comandos abaixo para compilar e gerar o executável em `bin/`:

```bash
mkdir -p Projeto_7/bin
g++ -std=c++17 -IProjeto_7/src -o Projeto_7/bin/projeto7 Projeto_7/src/*.cpp
```

Como executar
```bash
./Projeto_7/bin/projeto7
```

Exemplo de saída esperada

- Alunos com média > 7.0: João, Bruno
- Professores que ministram 'Programação': Carlos Souza
- Disciplinas cursadas por João em 2024: Matemática, Programação
- Alunos ordenados por nome: Bruno, João, Maria