#include <iostream>
#include <vector>
#include "pessoa.h"

int main() {
    Pessoa p1("Matheus Cavalcante", "4002-8922");
    Pessoa p2("Maria Eduarda", "9876-5432");
    Pessoa p3("Paulo Vitor", "5555-6666");

    std::vector<Pessoa> pessoas = {p1, p2, p3};

    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        std::cout << std::endl;  
    }

    return 0;
}
