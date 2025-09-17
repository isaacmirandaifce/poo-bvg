#include Professor.h
#include iostream

ProfessorProfessor(const stdstring& nome, const stdstring& email,
                     const stdstring& departamento)
     Usuario(nome, email, Professor), departamento(departamento) {}

void ProfessorexibirInformacoes() const {
    stdcout  Professor   nome  n;
    stdcout  Departamento   departamento  n;
    stdcout  Email   email  n;
    stdcout  Disciplinas ministradas   disciplinasMinistradas.size()  n;
}

void ProfessoradicionarDisciplina(Disciplina disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void ProfessorlistarDisciplinas() const {
    stdcout  Disciplinas ministradas por   nome  n;
    for (const auto& disc  disciplinasMinistradas) {
        stdcout   -   disc-getNome()   (  disc-getCodigo()  )n;
    }
}

stdstring ProfessorgetDepartamento() const { return departamento; }