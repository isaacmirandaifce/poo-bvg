#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> listaPessoas;

    // adicionando objetos ao vetor
    listaPessoas.emplace_back("Ana Silva", "1234-5678");
    listaPessoas.emplace_back("Carlos Souza", "9876-5432");
    listaPessoas.emplace_back("Beatriz Lima", "5555-0000");

    // mostrando as informações
    for (const Pessoa& p : listaPessoas) {
        p.imprimirNome();
        p.imprimirTelefone();
        cout << "--------------------------" << endl;
    }

    return 0;
}
