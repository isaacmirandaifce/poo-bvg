#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    std::vector<Pessoa> pessoas;

    // Adiciona 3 pessoas ao vector
    pessoas.emplace_back("João Silva", "1111-2222");
    pessoas.emplace_back("Maria Oliveira", "3333-4444");
    pessoas.emplace_back("Carlos Souza", "5555-6666");

    // Percorre o vector e imprime dados
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "------------------\n";
    }

    return 0;
}
