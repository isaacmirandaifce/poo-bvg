#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    std::vector<Pessoa> pessoas;

    // Adicionando 3 objetos Pessoa ao vector
    pessoas.emplace_back("Ana", "1111-2222");
    pessoas.emplace_back("Bruno", "3333-4444");
    pessoas.emplace_back("Carla", "5555-6666");

    // Percorrendo o vector e imprimindo nome e telefone
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "--------------------" << std::endl;
    }

    return 0;
}
