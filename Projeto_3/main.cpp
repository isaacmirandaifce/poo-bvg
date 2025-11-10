#include <iostream>
#include <vector>
#include "Pessoa.h"
using namespace std;

int main() {
    //Cria um vetor de objetos Pessoa
    vector<Pessoa> pessoas;

    //Adiciona objetos ao vetor
    pessoas.push_back(Pessoa("Ailton", "99999-1111"));
    pessoas.push_back(Pessoa("Renato", "98888-2222"));
    pessoas.push_back(Pessoa("Isaac", "97777-3333"));

    cout << "\n Lista de Pessoas: \n";

    //Percorre o vetor e exibe as informações
    for (int i = 0; i < pessoas.size(); i++)
    {
        pessoas[i].imprimirNome();
        pessoas[i].imprimirTelefone();
        cout << "-------------" << endl;
    }

    cout << "\nFim do programa.\n";
    return 0;
}