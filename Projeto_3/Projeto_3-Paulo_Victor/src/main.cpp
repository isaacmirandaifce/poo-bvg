#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    std::vector<Pessoa*> pessoas;

    pessoas.push_back(new Pessoa("Alice", "1234-5678"));
    pessoas.push_back(new Pessoa("Bob", "8765-4321"));
    pessoas.push_back(new Pessoa("Carol", "1122-3344"));

    for (const auto& pessoa : pessoas) {
        pessoa->imprimirNome();
        pessoa->imprimirTelefone();
        std::cout << std::endl;
    }

    for (auto pessoa : pessoas) {
        delete pessoa;
    }

    return 0;
}