#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    // Criando objetos Pessoa e adicionando ao vector:
    std::vector<Pessoa> pessoas;
    pessoas.push_back(Pessoa("Yudi Tamashiro", "4002-8922"));
    pessoas.push_back(Pessoa("Gabriel Contino", "2345-6789"));
    pessoas.push_back(Pessoa("Alexander Hamilton", "1755-1804"));

    // Percorrendo o vector e exibindo informações:
    for (auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
    }

    return 0;
}
