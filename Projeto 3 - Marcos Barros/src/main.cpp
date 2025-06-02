#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> pessoas;

    // Criando e adicionando objetos
    pessoas.emplace_back("João Silva", "9999-9999");
    pessoas.emplace_back("Maria Costa", "8888-8888");
    pessoas.emplace_back("Carlos Lima", "7777-7777");

    // Exibindo informações
    cout << "\nLista de Pessoas Cadastradas:\n";
    for (const Pessoa& p : pessoas) {
        p.imprimirNome();
        p.imprimirTelefone();
        cout << "--------------------------\n";
    }

    return 0;
}
