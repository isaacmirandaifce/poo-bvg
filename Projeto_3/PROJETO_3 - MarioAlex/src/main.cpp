#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> listaPessoas;
    int quantidade;

    cout << "Quantas pessoas deseja cadastrar? ";
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        string nome, telefone;
        cout << "\nPessoa " << (i + 1) << ":" << endl;
        cout << "Digite o nome: ";
        cin.ignore(); // limpa buffer
        getline(cin, nome);

        cout << "Digite o telefone: ";
        getline(cin, telefone);

        Pessoa p(nome, telefone);
        listaPessoas.push_back(p);
    }

    cout << "\n--- Lista de Pessoas ---" << endl;
    for (int i = 0; i < listaPessoas.size(); i++) {
        listaPessoas[i].imprimirNome();
        listaPessoas[i].imprimirTelefone();
        cout << "----------------------" << endl;
    }

    return 0;
}

