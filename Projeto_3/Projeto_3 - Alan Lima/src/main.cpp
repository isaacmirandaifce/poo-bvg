#include <iostream>
#include <vector>
#include "Pessoa.h" // Declaração da classe Pessoa

int main() {
    // Vetor de ponteiros para armazenar objetos Pessoa alocados dinamicamente
    std::vector<Pessoa*> lista;

    lista.push_back(new Pessoa("Joao Silva", "1234-5678"));
    lista.push_back(new Pessoa("Maria Oliveira", "8765-4321"));
    lista.push_back(new Pessoa("Carlos Pereira", "5555-9999"));

    // Imprimindo os dados das pessoas
    std::cout << "Lista de Pessoas:" << std::endl;
    for (const auto& pessoa : lista) {
        pessoa->imprimirNome();
        pessoa->imprimirTelefone();
        std::cout << "------------------" << std::endl;
    }

    // Liberando a memória alocada com "delete"
    for (auto& pessoa : lista) {
        delete pessoa; // Chama o destrutor explicitamente
    }

    // Limpando o vetor (não obrigatório, mas boa prática)
    lista.clear();

    return 0;
}
