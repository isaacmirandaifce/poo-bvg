#include <iostream>
#include <vector>
#include "Contato.h"

using namespace std;

int main() {
    vector<Contato> contatos;

    contatos.push_back(Contato("Empresa Alpha", "(85) 99999-1111"));
    contatos.push_back(Contato("Empresa Beta", "(85) 98888-2222"));
    contatos.push_back(Contato("Empresa Gama", "(85) 97777-3333"));

    for (int i = 0; i < contatos.size(); i++) {
        cout << "--- Contato " << i + 1 << " ---" << endl;
        contatos[i].imprimirNome();
        contatos[i].imprimirTelefone();
    }

    return 0;
}