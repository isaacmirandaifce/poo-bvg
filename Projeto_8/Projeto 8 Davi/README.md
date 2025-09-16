# Projeto Avaliativo 8 — Tratamento de Exceções e Sinais (C++)

## Como compilar (g++ 11+)
```bash
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o sistema
```
No Windows (MinGW):
```bash
g++ -std=c++17 -Iinclude src\\*.cpp main.cpp -o sistema.exe
```

## Como executar
```bash
./sistema
```
Os dados serão salvos em `./data/*.csv` automaticamente a cada inclusão ou ao encerrar.

## Sinais tratados
- `SIGINT` (Ctrl+C) — tenta salvar e encerra com segurança
- `SIGTERM` — tenta salvar e encerra com segurança
- `SIGSEGV` — imprime aviso e encerra imediatamente (não é seguro salvar)

## Exceções personalizadas
- `ArquivoNaoEncontradoException`
- `PermissaoNegadaException`
- `ConversaoDadosException`
- `PersistenciaException` (base)

## Estrutura de arquivos
```
include/
  Aluno.h
  Professor.h
  Disciplina.h
  Excecoes.h
  Persistencia.h
  SinalHandler.h
  SistemaAcademico.h
src/
  Aluno.cpp
  Professor.cpp
  Disciplina.cpp
  Persistencia.cpp
  SinalHandler.cpp
  SistemaAcademico.cpp
main.cpp
data/
  alunos.csv (gerado)
  professores.csv (gerado)
  disciplinas.csv (gerado)
```

## Formato dos CSVs
- `alunos.csv`: `id;nome;curso`
- `professores.csv`: `id;nome;area`
- `disciplinas.csv`: `codigo;nome;cargaHoraria`

As primeiras linhas são cabeçalhos e são ignoradas na leitura.

🔹 1. Abrir o terminal no VS Code

No VS Code: Ctrl + ' (atalho para abrir o terminal integrado).

Confirme que está na pasta do projeto, senão use:

cd "C:\Users\dn212\OneDrive\Área de Trabalho\Projeto 8 Davi"

🔹 2. Compilar

No Windows é melhor gerar .exe (para evitar conflito com o Wireshark):

g++ -std=c++17 -Wall -Wextra -Iinclude -o projeto8.exe src/*.cpp


👉 Isso cria o executável projeto8.exe dentro da mesma pasta.

🔹 3. Executar

Agora rode assim:

.\projeto8.exe