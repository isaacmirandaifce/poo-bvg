#include <iostream>
#include "Aluno.h"

using namespace std;

// ----- Classe interna HistoricoDisciplinar -----

Aluno::HistoricoDisciplinar::HistoricoDisciplinar() : disciplina(""), ano(0), nota(0.0) {}

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(string disciplina, int ano, double nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

string Aluno::HistoricoDisciplinar::getDisciplina() const {
    return disciplina;
}

int Aluno::HistoricoDisciplinar::getAno() const {
    return ano;
}

double Aluno::HistoricoDisciplinar::getNota() const {
    return nota;
}

void Aluno::HistoricoDisciplinar::exibir() const {
    cout << "  - " << disciplina << " (" << ano << "): nota " << nota << endl;
}

// ----- Classe Aluno -----

Aluno::Aluno() : UsuarioAutenticavel(), matricula(""), curso("") {}

Aluno::Aluno(string nome, string email, const string& senha, string matricula, string curso)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha),
      matricula(matricula), curso(curso) {}

void Aluno::adicionarHistorico(const string& disciplina, int ano, double nota) {
    historico.push_back(HistoricoDisciplinar(disciplina, ano, nota));
}

bool Aluno::autenticar(string senha) {
    return validarSenha(senha);
}

void Aluno::gerarRelatorio() const {
    cout << "[Relatorio de Aluno - " << tipoUsuarioParaTexto(tipo) << "]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
    cout << "Historico disciplinar:" << endl;
    if (historico.empty()) {
        cout << "  nenhum registro" << endl;
    }
    for (const auto& item : historico) {
        item.exibir();
    }
}

void Aluno::exibirInformacoes() const {
    cout << "Aluno: " << nome << " | Matricula: " << matricula << " | Curso: " << curso << endl;
}

void Aluno::exibirInformacoes(bool comHistorico) const {
    exibirInformacoes();
    if (comHistorico) {
        cout << "Historico:" << endl;
        if (historico.empty()) {
            cout << "  sem registros" << endl;
        }
        for (const auto& item : historico) {
            item.exibir();
        }
    }
}
