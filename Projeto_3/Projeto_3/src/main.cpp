#include <iostream>
#include <vector>
#include "Pessoa.H"

int main() {
    std::vector<Pessoa> pessoas;

    // Adicionando objetos ao vetor
    pessoas.emplace_back("Larissa Vieira", "111-222-333");
    pessoas.emplace_back("José Jhonata", "863-798-355");
    pessoas.emplace_back("Sandra Maria", "123-456-789");

    // Percorrendo o vetor e exibindo as informações
    for (const auto &pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << "--------------------" << std::endl;
    }

    return 0;
}
