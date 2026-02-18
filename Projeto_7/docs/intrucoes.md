
# Projeto 7 — Sistema Genérico de Filtragem (Templates + std::function)
## Aluno: João Paulo de Albuquerque ALves
## Objetivo
Implementar um **sistema genérico de filtragem** utilizando **templates** e **std::function**, integrando com o sistema acadêmico (Aluno/Professor) e demonstrando:
- Filtragens com condição (lambda)
- Impressão genérica (função/lambda)
- Ordenação genérica (comparador)

---

## Principais Implementações

### 1) Template `Filtro<T>` (`src/Filtro.h`)
Classe genérica responsável por armazenar elementos e executar operações reutilizáveis:

- `adicionarElemento(const T&)` → adiciona itens ao filtro  
- `filtrarPorCondicao(function<bool(const T&)>)` → retorna lista filtrada por regra (lambda)  
- `imprimirTodos(function<void(const T&)>)` → imprime/exec. ação em cada elemento  
- `ordenar(function<bool(const T&, const T&)>)` → ordena por critério genérico (nome, média, etc.)

---

### 2) Extensões no `Aluno`
Para suportar os filtros do projeto:
- `calcularMedia()` → calcula a média com base no histórico
- `getHistorico()` → permite acessar o histórico para filtrar por ano
- `HistoricoDisciplinar` (classe interna) com getters (`getDisciplina()`, `getAno()`, `getNota()`)

---

### 3) Extensões no `Professor`
Para suportar filtragem por disciplina:
- Lista `disciplinasMinistradas`
- `adicionarDisciplinaMinistrada()` → adiciona disciplinas
- `ministra(disciplina)` → verifica se ministra uma disciplina específica

---

## Demonstrações no `main.cpp`
O `main.cpp` executa testes que comprovam a implementação:

1. **Filtro de alunos com média > 7.0**
2. **Filtro de professores que ministram uma disciplina (ex.: "POO")**
3. **Filtro de disciplinas cursadas por um aluno em um ano (ex.: 2024)**
4. **Ordenação genérica** (por nome e por média)

---

## Como Compilar e Executar (Codespaces / Linux)
Na raiz do repositório:

```bash
cd Projeto_7
g++ -std=c++17 src/*.cpp -o app
./app
