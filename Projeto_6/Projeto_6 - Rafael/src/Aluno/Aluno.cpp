#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(string disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() {
    cout << "- " << disciplina << " | Ano: " << ano << " | Nota: " << nota << endl;
}

Aluno::Aluno() : UsuarioAutenticavel(), matricula(""), curso(""), disciplinas({}), tipoUsuario(TipoUsuario::ALUNO) {}

Aluno::Aluno(string nome, string email, string tipo, string senha, string matricula, string curso, vector<string> disciplinas)
    : UsuarioAutenticavel(nome, email, tipo, senha), matricula(matricula), curso(curso), disciplinas(disciplinas), tipoUsuario(TipoUsuario::ALUNO) {}

void Aluno::gerarRelatorio() {
    cout << "=== RELATORIO DE ALUNO ===" << endl;
    cout << "Nome: " << nome << ", Email: " << email << ", Tipo: " << tipo << endl;
    cout << "Matricula: " << matricula << ", Curso: " << curso << endl;
    cout << "Disciplinas: ";
    for (auto d : disciplinas) cout << d << " ";
    cout << endl << "Historico Disciplinar:" << endl;
    for (auto h : historico) h.exibir();
    cout << endl;
}

bool Aluno::autenticar(string senhaTentativa) {
    return senhaTentativa == senha;
}

void Aluno::adicionarDisciplinaAoHistorico(string disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}