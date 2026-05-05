#include "Professor.h"

using namespace std;

Professor::Professor(string nome, string email, string area, vector<string> disciplinas)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(area), disciplinasMinistradas(disciplinas) {}

void Professor::gerarRelatorio() {
    cout << "--- Relatorio de Professor ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Area: " << areaDeAtuacao << endl;
    cout << "Disciplinas Ministradas: ";

    if (disciplinasMinistradas.empty()) {
        cout << "Nenhuma registrada.";
    } else {
        for (const string& d : disciplinasMinistradas) {
            cout << "[" << d << "] ";
        }
    }
    cout << endl;
}
