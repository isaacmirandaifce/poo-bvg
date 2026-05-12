#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {

    // Criando o container vector para armazenar objetos do tipo Pessoa
    vector<Pessoa> pessoas;

    // Adicionando objetos Pessoa ao vector usando o construtor parametrizado
    pessoas.push_back(Pessoa("Carlos Silva", "(85) 99876-5432"));
    pessoas.push_back(Pessoa("Ana Souza", "(85) 98765-4321"));
    pessoas.push_back(Pessoa("Bruno Lima", "(85) 91234-5678"));

    cout << "\n=== Lista de Contatos ===" << endl;

    // Percorrendo o vector e exibindo as informações de cada Pessoa
    for (int i = 0; i < pessoas.size(); i++) {
        cout << "\nPessoa " << i + 1 << ":" << endl;
        pessoas[i].imprimirNome();
        pessoas[i].imprimirTelefone();
    }

    cout << "\n=== Fim do programa ===" << endl;

    return 0;
}
