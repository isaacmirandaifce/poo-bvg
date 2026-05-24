#include "Professor.h"

Professor::Professor() : Usuario() {
    areaDeAtuacao = "";
}

Professor::Professor(string nome,
                     string email,
                     string areaDeAtuacao)
    : Usuario(nome, email, "Professor") {

    this->areaDeAtuacao = areaDeAtuacao;
}

void Professor::adicionarDisciplina(string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() {

    cout << "\n===== RELATORIO DO PROFESSOR =====" << endl;

    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Area de Atuacao: "
         << areaDeAtuacao << endl;

    cout << "Disciplinas Ministradas:" << endl;

    for (string d : disciplinasMinistradas) {
        cout << "- " << d << endl;
    }
}

Professor::~Professor() {
}