#  Projeto: Gerenciamento de Notas de Alunos (C++)

Este projeto tem como objetivo consolidar os conhecimentos de **modularização**, **modificadores de acesso** e **funções amigas** em C++ por meio da criação de um sistema simples de gerenciamento de notas de alunos para diferentes disciplinas.


# Estrutura do Projeto

ProjetoNotas/
├── Aluno.h
├── Aluno.cpp
├── Disciplina.h
├── Disciplina.cpp
└── main.cpp


#  Funcionalidades

- Cadastro de alunos com nome, matrícula e curso.
- Registro de disciplinas com nome, carga horária e nota.
- Cálculo de status de aprovação (nota ≥ 6.0).
- Exibição das informações do aluno e das disciplinas associadas.



# Classes

# 📘 Classe `Aluno`

**Atributos (privados):**
- `nome` (string): nome completo do aluno.
- `matricula` (string): número de matrícula.
- `curso` (string): nome do curso.

**Métodos:**
- `Aluno()`: construtor padrão.
- `Aluno(nome, matricula, curso)`: construtor parametrizado.
- `void exibirInformacoes() const`: exibe os dados do aluno.



# Classe `Disciplina`

**Atributos (privados):**
- `nome` (string): nome da disciplina.
- `cargaHoraria` (int): carga horária da disciplina.
- `nota` (float): nota do aluno na disciplina.

**Métodos:**
- `Disciplina()`: construtor padrão.
- `Disciplina(nome, cargaHoraria, nota)`: construtor parametrizado.
- `void setNota(float)`: define a nota.
- `float getNota() const`: retorna a nota.
- `void exibirDados() const`: exibe os dados da disciplina.
- `friend bool verificarAprovacao(const Disciplina&)`: função amiga que verifica se a nota é ≥ 6.0.



# Execução do Programa

A função principal (`main`) realiza as seguintes ações:

- Cria um objeto `Aluno`.
- Cria duas disciplinas associadas.
- Exibe as informações do aluno.
- Exibe os dados de cada disciplina e verifica a aprovação usando a função amiga.



# Requisitos Atendidos

- [x] Modularização (arquivos separados .h/.cpp)
- [x] Uso adequado de modificadores de acesso (`private`, `public`)
- [x] Uso de função amiga (`friend`) para verificação de aprovação
- [x] Estrutura clara e boas práticas
- [x] Diagrama UML incluso

