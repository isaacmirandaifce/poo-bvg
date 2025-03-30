#include <iostream>   // Para entrada/saída
#include <vector>     // Para o container std::vector
#include "Pessoa.h"   // Para a classe Pessoa

int main() {
    // Criando um vetor de pessoas
    std::vector<Pessoa> pessoas;

    // Adicionando pessoas ao vetor
    pessoas.emplace_back("Ana Silva", "1234-5678");
    pessoas.emplace_back("João Souza", "9876-5432");
    pessoas.emplace_back("Maria Oliveira", "5678-1234");

    // Percorrendo o vetor e exibindo as informações
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "---------------------" << std::endl;
    }

    return 0;
}
