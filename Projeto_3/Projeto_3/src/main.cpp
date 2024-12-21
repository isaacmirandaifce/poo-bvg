#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    std::vector<Pessoa> pessoas;

    // Adicionando objetos ao vetor
    pessoas.emplace_back("Jhonata Vieira", "123-456-789");
    pessoas.emplace_back("Luna Vieira", "937-738-333");
    pessoas.emplace_back("Carlos Souza", "111-222-333");

    // Percorrendo o vetor e exibindo as informações
    for (const auto &pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "--------------------" << std::endl;
    }

    return 0;
}
