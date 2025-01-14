#include <iostream>
#include <vector>
#include <memory>
#include "Pessoa.h"

int main() {
    std::vector<std::unique_ptr<Pessoa>> pessoas;

    pessoas.emplace_back(std::make_unique<Pessoa>("Joãozinho", "236-8432"));
    pessoas.emplace_back(std::make_unique<Pessoa>("Toinho", "190-5223"));
    pessoas.emplace_back(std::make_unique<Pessoa>("Maria", "000-0976"));

    for (const auto& pessoa : pessoas) {
        pessoa->imprimirNome();
        pessoa->imprimirTelefone();
        std::cout << std::endl;
    }

    return 0;
}
