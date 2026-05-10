#include <iostream>
#include <vector>
#include "contato.h"

int main() {
    std::vector<Contato> agenda;

    agenda.reserve(3);

    agenda.push_back(Contato("Alice Silva", "91111-1111"));
    agenda.push_back(Contato("Samuel Viktor", "92222-2222"));
    agenda.push_back(Contato("Renan Pereira", "93333-3333"));

    std::cout << "\n--- Lista de Contatos ---" << std::endl;

    for(size_t i = 0; i < agenda.size(); i++) {
        agenda[i].imprimirNome();
        agenda[i].imprimirTelefone();
        std::cout << "-----------" << std::endl;
    }

    std::cout << "Limpando a memoria e encerrando o programa" << std::endl;

    return 0;
}