#include <iostream>
#include <vector>
#include <string>
#include "Contato.h"

int main() {
    std::cout << "=== CRM Enterprise - Módulo de Contatos B2B ===\n" << std::endl;

    // Container dinâmico (substitui arrays fixos como Contato contatos[10])
    std::vector<Contato> contatos;

    // Reserva espaço para evitar realocações do vector durante os push_back.
    contatos.reserve(3);

    // Instanciando contatos de clientes corporativos.
    contatos.push_back(Contato("Tech Solutions Ltda", "(85) 3222-1000"));
    contatos.push_back(Contato("Global Logística S.A.", "(85) 3344-2000"));
    contatos.push_back(Contato("Nordeste Agro Comércio", "(85) 3555-3000"));

    std::cout << "\n--- Listagem de contatos ---\n" << std::endl;

    // Iteração pelo vector
    for (std::size_t i = 0; i < contatos.size(); i++) {
        std::cout << "Contato #" << (i + 1) << std::endl;
        contatos[i].imprimirNome();
        contatos[i].imprimirTelefone();
        std::cout << "----------------------------" << std::endl;
    }

    std::cout << "\nFim do programa. Os contatos serão desalocados:\n" << std::endl;
    return 0;
}