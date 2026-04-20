#include "Aluno.h"

using namespace std;

Aluno::Aluno(string nome, string email, string matricula, string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::gerarRelatorio() {
    cout << "--- Relatorio de Aluno ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Curso: " << curso << endl;
}

void Aluno::exibirDetalhes() {
    cout << "Aluno: " << nome << " | Curso: " << curso << endl;
}

void Aluno::exibirDetalhes(bool comNotas) {
    cout << "Aluno: " << nome << " (" << matricula << ")" << endl;
    if (comNotas) {
        cout << "Historico de notas: [Visualizacao restrita ao sistema]" << endl;
    } else {
        cout << "Historico de notas: Omitido." << endl;
    }
}
