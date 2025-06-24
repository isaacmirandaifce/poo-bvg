#include <iostream>
#include <vector>
#include "Pessoa.h"

void exibirListaPessoas(const std::vector<Pessoa>& pessoas) {
    std::cout << "\nLista de Pessoas:\n";
    std::cout << "-----------------\n";
    
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Pessoa> pessoas;
    
    // Adicionando pessoas
    pessoas.emplace_back("João Silva", "(11) 9999-8888");
    pessoas.emplace_back("Maria Oliveira", "(21) 7777-6666");
    pessoas.emplace_back("Carlos Souza", "(31) 5555-4444");
    
    exibirListaPessoas(pessoas);
    
    return 0;
}