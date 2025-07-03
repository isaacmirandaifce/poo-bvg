#include "Aluno.h"
#include <iostream>
#include <iomanip>
using namespace std;

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(string disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    cout << "- " << disciplina << " | Ano: " << ano << " | Nota: " << fixed << setprecision(1) << nota << endl;
}

float Aluno::HistoricoDisciplinar::getNota() const {
    return nota;
}

Aluno::Aluno() : UsuarioAutenticavel(), matricula(""), curso(""), disciplinas({}), tipoUsuario(TipoUsuario::ALUNO) {}

Aluno::Aluno(string nome, string email, string tipo, string senha, string matricula, string curso, vector<string> disciplinas)
    : Usuario(nome, email, tipo),  // <- CHAMADA DIRETA
      UsuarioAutenticavel(nome, email, tipo, senha),
      matricula(matricula),
      curso(curso),
      disciplinas(disciplinas),
      tipoUsuario(TipoUsuario::ALUNO) {}

void Aluno::gerarRelatorio() const {
    cout << "=== RELATORIO DE ALUNO ===" << endl;
    cout << "Nome: " << nome << ", Email: " << email << ", Tipo: " << tipo << endl;
    cout << "Matricula: " << matricula << ", Curso: " << curso << endl;
    cout << "Disciplinas: ";
    for (const auto& d : disciplinas) cout << d << " ";
    cout << endl << "Historico Disciplinar:" << endl;
    for (const auto& h : historico) h.exibir();
    cout << "Media Geral: " << fixed << setprecision(2) << getMedia() << endl;
    cout << endl;
}

bool Aluno::autenticar(string senhaTentativa) {
    return senhaTentativa == senha;
}

void Aluno::adicionarDisciplinaAoHistorico(string disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}

float Aluno::getMedia() const {
    if (historico.empty()) return 0.0;
    float soma = 0;
    for (const auto& h : historico) {
        soma += h.getNota();
    }
    return soma / historico.size();
}

string Aluno::getNome() const {
    return nome;
}

string Aluno::getMatricula() const {
    return matricula;
}

string Aluno::getCurso() const {
    return curso;
}

string Aluno::getEmail() const {
    return email;
}

vector<string> Aluno::getDisciplinas() const {
    return disciplinas;
}