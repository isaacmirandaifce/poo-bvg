#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno(const string& nome, const string& email, const string& senha)
    : UsuarioAutenticavel(nome, email, senha, TipoUsuario::ALUNO) {} // Passa TipoUsuario::ALUNO

bool Aluno::autenticar(const string& senha) const {
    return this->senha == senha;
}

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << "\nEmail: " << email << "\nHistórico Disciplinar:\n";
    for (const auto& disciplina : historico) {
        cout << " - " << disciplina.nomeDisciplina << " (Ano: " << disciplina.ano 
             << ", Nota: " << disciplina.nota << ")\n";
    }
}

void Aluno::adicionarDisciplina(const string& nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota);
}

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const string& nome, int ano, float nota)
    : nomeDisciplina(nome), ano(ano), nota(nota) {}
