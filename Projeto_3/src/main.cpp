#include <iostream>
#include <vector> // Biblioteca de vetores dinâmicos 
#include "contato.h"

int main() {
    std::vector<Contato> agenda; 

    agenda.reserve(3); // Otimização: reserva espaço para evitar realocações e logs extras.

    // Contatos usando push_back
    agenda.push_back(Contato("Alice Silva", "91111-1111"));
    agenda.push_back(Contato("Samuel Viktor", "92222-2222"));
    agenda.push_back(Contato("Renan Pereira", "93333-3333"));

    std::cout << "\n--- Lista de Contatos ---" << std::endl;

    // Percorre o vector usando .size() para garantir o domínio da STL sem estourar limites.
    for(size_t i = 0; i < agenda.size(); i++) {
        agenda[i].imprimirNome();
        agenda[i].imprimirTelefone();
        std::cout << "-----------" << std::endl;
    }

    std::cout << "Limpando a memoria e encerrando o programa" << std::endl;

    return 0;
}