#include "Aluno.h"

Aluno::Aluno() : UsuarioAutenticavel() {
    matricula = "NULL";
    curso = "NULL";
}

Aluno::Aluno(string nome, string email, string senha, string matricula, string curso)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha) {
    this->matricula = matricula;
    this->curso = curso;
}

bool Aluno::autenticar(string senha) {
    return this->senha == senha;
}

void Aluno::adicionarHistorico(string disciplina, int ano, float nota) {
    historico.push_back(HistoricoDisciplinar(disciplina, ano, nota));
}

void Aluno::gerarRelatorio() const {
    cout << "\n--- RELATÓRIO DO ALUNO ---\n";
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Matrícula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
    cout << "Histórico:\n";
    for (auto &h : historico) {
        h.exibir();
    }
}
