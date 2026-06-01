#include <iostream>
#include <vector>
#include "Contato.h"

int main() {
    std::cout << "--- Iniciando Modulo de Contatos B2B (CRM) ---\n\n";

    // Criando o container dinâmico de Contatos
    std::vector<Contato> listaContatos;

    // Instanciando e adicionando pelo menos 3 contatos corporativos
    listaContatos.push_back(Contato("Tech Solutions S.A.", "+55 11 99999-0001"));
    listaContatos.push_back(Contato("Global Inovacao", "+55 21 88888-0002"));
    listaContatos.push_back(Contato("Industrias Apex", "+55 31 77777-0003"));

    std::cout << "--- Lista de Clientes Cadastrados ---\n";
    
    // Laço de iteração para percorrer o vector
    for (size_t i = 0; i < listaContatos.size(); i++) {
        std::cout << "Cliente #" << (i + 1) << "\n";
        listaContatos[i].imprimirNome();
        listaContatos[i].imprimirTelefone();
        std::cout << "-----------------------------------\n";
    }

    std::cout << "\nEncerrando o programa. Limpando memoria...\n";
    
    // Ao final do bloco main, os objetos saem de escopo e os destrutores serão chamados automaticamente.
    return 0;
}