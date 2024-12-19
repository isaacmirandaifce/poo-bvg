#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    // Criando um vector para armazenar objetos Pessoa
    std::vector<Pessoa> pessoas;

    // Adicionando objetos Pessoa ao vector usando push_back
    pessoas.push_back(Pessoa("Gabys", "9880-0000"));
    pessoas.push_back(Pessoa("Mandysan", "9880-7394"));
    pessoas.push_back(Pessoa("Irineldis", "8998-0987"));

    // Percorrendo o vector e exibindo informações
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "-----\n";
    }

    return 0;
}
