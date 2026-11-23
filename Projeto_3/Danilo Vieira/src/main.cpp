#include <iostream>
#include <vector>
#include "Contato.h"

int main() {
    std::vector<Contato> contatos;

    contatos.reserve(3);

    contatos.push_back(Contato("Empresa Alfa", "(88) 99999-1111"));
    contatos.push_back(Contato("Empresa Beta", "(88) 99999-2222"));
    contatos.push_back(Contato("Empresa Gama", "(88) 99999-3333"));

    std::cout << "=== CRM ENTERPRISE ===" << std::endl;

    for (const Contato& contato : contatos) {
        std::cout << "----------------------" << std::endl;
        contato.imprimirNome();
        contato.imprimirTelefone();
    }

    std::cout << "----------------------" << std::endl;
    std::cout << "Total de contatos: "
              << contatos.size() << std::endl;

    return 0;
}
