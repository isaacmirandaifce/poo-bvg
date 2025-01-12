#include <iostream>
#include <vector>
#include "Pessoa.h"

int main() {
    // Cria um vetor de objetos Pessoa
    std::vector<app::Pessoa> pessoas;

    // Adiciona os objetos no vetor
    pessoas.emplace_back("Maria Fernanda", "8899635-9874");
    pessoas.emplace_back("João Antônio", "9876543-2109");
    pessoas.emplace_back("Pedro Silva", "7654321-0987");

    // Percorre o vetor e exibe as informações
    for (const auto &pessoa : pessoas) {
        pessoa.imprimirNome();      // Chama o método para imprimir o nome
        pessoa.imprimirTelefone(); // Chama o método para imprimir o telefone
    }

    return 0;
}