#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> pessoas;

    pessoas.emplace_back("Alice", "1234-5678");
    pessoas.emplace_back("Bob", "8765-4321");
    pessoas.emplace_back("Carol", "4567-8901");

    cout << "\nLista de pessoas armazenadas no vector:\n";
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
    }
    system("pause");
    return 0;
}
