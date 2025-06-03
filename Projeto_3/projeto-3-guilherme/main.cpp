#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> listaPessoas;

    // Adicionando 3 objetos
    listaPessoas.push_back(Pessoa("Alice", "1234-5678"));
    listaPessoas.push_back(Pessoa("Bruno", "2345-6789"));
    listaPessoas.push_back(Pessoa("Carlos", "3456-7890"));

    // Percorrendo o vector e exibindo informações
    for (Pessoa& p : listaPessoas) {
        p.imprimirNome();
        p.imprimirTelefone();
        cout << endl;
    }

    return 0;
}
