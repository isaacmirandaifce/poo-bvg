#include <iostream>
#include <vector>
#include "pessoa.h"

int main() {
    // Cria os objetos:
    std::vector<Pessoa> pessoas;
    pessoas.push_back(Pessoa("Uati", "0000-0000"));
    pessoas.push_back(Pessoa("Zapi", "1111-1111"));
    pessoas.push_back(Pessoa("Da Silva", "2222-2222"));

    // Exibe as informaçoes:
    for (auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
    }

    return 0;
}