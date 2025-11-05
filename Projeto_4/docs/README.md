# Projeto Avaliativo 4 — Gerenciamento de Notas de Alunos

Este projeto implementa um sistema simples em C++ para gerenciar notas de alunos, focando em:

- Modularização (arquivos separados .h/.cpp).
- Modificadores de acesso (atributos privados, métodos públicos).
- Uso de função amiga (`friend`) para verificar aprovação.

O código de exemplo cria um objeto `Aluno`, associa pelo menos duas `Disciplina`, atribui notas e usa a função amiga `verificarAprovacao` para determinar se o aluno foi aprovado (nota >= 6.0).

## Estrutura do projeto (arquivos principais)

- `src/Aluno.h` / `src/Aluno.cpp` — classe `Aluno` (atributos: `nome`, `matricula`, `curso`) e associação com `Disciplina`.
- `src/Disciplina.h` / `src/Disciplina.cpp` — classe `Disciplina` (atributos: `nome`, `cargaHoraria`, `nota`) e função amiga `verificarAprovacao`.
- `src/main.cpp` — programa principal que demonstra criação de objetos e verificação de aprovação.

## Como compilar e executar

Abra um terminal na pasta `Projeto_4/` e execute:

```bash
cd /workspaces/poo-bvg/Projeto_4
mkdir -p bin
g++ -std=c++17 -Wall -Wextra src/*.cpp -o bin/projeto4
./bin/projeto3
```
