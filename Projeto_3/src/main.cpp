#include <iostream>
#include <vector>
#include "Pessoa.h"
using namespace std;

int main() {
    vector<Pessoa> listaDePessoas;
    Pessoa p1("Emyliano Carvalho", "(11) 1111-1111");
    Pessoa p2("Lucas Galindo", "(22) 2222-2222");
    Pessoa p3("Kelvin Vaz", "(33) 3333-3333");

    listaDePessoas.push_back(p1);
    listaDePessoas.push_back(p2);
    listaDePessoas.push_back(p3);
    cout << "=== Lista de Contatos ===" << endl;

    for (size_t i = 0; i < listaDePessoas.size(); i++) {
        listaDePessoas[i].imprimirNome();
        listaDePessoas[i].imprimirTelefone();
        cout << "-------------------------" << endl;
    }
    return 0;
}