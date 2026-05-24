#include "Aluno.h"

Aluno::Aluno() : Usuario() {
    matricula = "";
    curso = "";
}

Aluno::Aluno(string nome, string email,
             string matricula, string curso)
    : Usuario(nome, email, "Aluno") {

    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::adicionarDisciplina(string disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() {
    cout << "\n===== RELATORIO DO ALUNO =====" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;

    cout << "Disciplinas:" << endl;

    for (string d : disciplinas) {
        cout << "- " << d << endl;
    }
}

// Sobrecarga sem nota
void Aluno::exibirInformacoes() {
    cout << "\nAluno: " << nome << endl;
    cout << "Curso: " << curso << endl;
}

// Sobrecarga com nota
void Aluno::exibirInformacoes(float nota) {
    cout << "\nAluno: " << nome << endl;
    cout << "Curso: " << curso << endl;
    cout << "Nota: " << nota << endl;
}

Aluno::~Aluno() {
}