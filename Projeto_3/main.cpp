#include <iostream>
#include <vector>
#include <memory>
#include "Pessoa.h"

int main() {
    std::vector<std::unique_ptr<Pessoa>> pessoas;

    pessoas.emplace_back(std::make_unique<Pessoa>("Alice", "123-4567"));
    pessoas.emplace_back(std::make_unique<Pessoa>("Bob", "987-6543"));
    pessoas.emplace_back(std::make_unique<Pessoa>("Carol", "555-1234"));

    for (const auto& pessoa : pessoas) {
        pessoa->imprimirNome();
        pessoa->imprimirTelefone();
        std::cout << std::endl;
    }

    return 0;
}