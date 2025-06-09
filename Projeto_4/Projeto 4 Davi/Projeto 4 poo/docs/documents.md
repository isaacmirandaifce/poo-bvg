📁 Projeto: Gerenciamento de Notas de Alunos (C++)
📚 Objetivo
Este projeto tem como objetivo consolidar os conhecimentos em C++ sobre modularização, modificadores de acesso (public/private) e funções amigas (friend), utilizando um sistema prático de gerenciamento de notas de alunos.

🧩 Arquivos e Estrutura
css
Copiar código
Projeto/
│
├── Aluno.h
├── Aluno.cpp
├── Disciplina.h
├── Disciplina.cpp
├── main.cpp
└── docs/
    └── README.md (você está aqui)
📘 Descrição das Classes
🔹 Aluno
Representa um aluno da instituição.

Atributos:
std::string nome — Nome completo do aluno.

std::string matricula — Matrícula do aluno.

std::string curso — Curso em que o aluno está matriculado.

Métodos:
Aluno() — Construtor padrão.

Aluno(std::string, std::string, std::string) — Construtor parametrizado.

void exibirInformacoes() — Exibe na tela as informações básicas do aluno.

🔹 Disciplina
Representa uma disciplina cursada pelo aluno.

Atributos:
std::string nome — Nome da disciplina.

int cargaHoraria — Carga horária da disciplina.

float nota — Nota obtida pelo aluno na disciplina.

Métodos:
Disciplina() — Construtor padrão.

Disciplina(std::string, int, float) — Construtor parametrizado.

void setNota(float) — Atualiza a nota da disciplina.

float getNota() — Retorna a nota atual.

🔸 Função amiga: verificarAprovacao
cpp
Copiar código
bool verificarAprovacao(const Disciplina& disciplina);
Permite acessar diretamente o atributo nota da classe Disciplina, mesmo sendo private.

Critério de aprovação:

Aprovado se nota ≥ 6.0

🖥️ main.cpp - Execução Principal
Cria um objeto do tipo Aluno.

Cria duas disciplinas.

Exibe as informações do aluno.

Verifica e imprime na tela se o aluno está aprovado ou reprovado em cada disciplina, utilizando a função amiga verificarAprovacao.

🔐 Modificadores de Acesso
Os atributos das classes estão como private para garantir encapsulamento.

Os métodos públicos controlam o acesso aos dados.

A função amiga tem permissão especial para acessar nota diretamente, sem precisar de um getNota() externo.

📋 Exemplo de Saída Esperada
makefile
Copiar código
Nome: Carlos Silva
Matrícula: 202312345
Curso: ADS

--- Status das Disciplinas ---
Programação: Aprovado
Banco de Dados: Reprovado
📈 Diagrama UML (resumo textual)
pgsql
Copiar código
+----------------+
|     Aluno      |
+----------------+
| - nome: string |
| - matricula: string |
| - curso: string |
+----------------+
| +Aluno()       |
| +Aluno(nome, matricula, curso) |
| +exibirInformacoes(): void     |
+----------------+

+----------------------+
|     Disciplina       |
+----------------------+
| - nome: string       |
| - cargaHoraria: int  |
| - nota: float        |
+----------------------+
| +Disciplina()        |
| +Disciplina(nome, ch, nota) |
| +setNota(float): void|
| +getNota(): float    |
| +friend verificarAprovacao |
+----------------------+