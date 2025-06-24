#include <iostream>
#include <vector>
#include "src/Pessoa.h"

using namespace std;

int main() {
    // Criando objetos Pessoa
    Pessoa *pessoa0 = new Pessoa();
    Pessoa *pessoa1 = new Pessoa("Rafael", "(88) 99804-3347");
    Pessoa *pessoa2 = new Pessoa("Pessoa2", "(88) 99999-9999");
    Pessoa *pessoa3 = new Pessoa("Pessoa3", "(88) 90000-0000");

    // Armazenando ponteiros no vector
    vector<Pessoa*> pessoas;
    pessoas.push_back(pessoa0);
    pessoas.push_back(pessoa1);
    pessoas.push_back(pessoa2);
    pessoas.push_back(pessoa3);

    cout << endl << "Objeto pessoa inicializado sem parâmetros" << endl;
    pessoa0->imprimirDados();

    // Exibindo informações
    for (int i = 1; i < pessoas.size(); i++) {
        pessoas[i]->imprimirDados();
    }

    // Liberar memória
    for (Pessoa* p : pessoas) {
        delete p;
    }

    return 0;
}