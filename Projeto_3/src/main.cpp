#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    std::vector<Pessoa> pessoas;

    pessoas.emplace_back("Maria", "11999999998");
    pessoas.emplace_back("Joao", "11888888887");
    pessoas.emplace_back("Ana", "11777777776");

    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
