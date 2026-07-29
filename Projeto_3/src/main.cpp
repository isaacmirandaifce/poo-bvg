#include <iostream>
#include <vector>
#include "Contato.h"

using namespace std;

int main() {
    cout << "=== CRM Enterprise: Modulo de Gestao de Contatos ===" << endl << endl;

    // Criando um container dinâmico std::vector
    vector<Contato> listaContatos;

    // Adicionando contatos corporativos ao vector usando push_back
    listaContatos.push_back(Contato("TechSolutions Ltda", "(85) 98888-1111"));
    listaContatos.push_back(Contato("Genesis HighTech", "(88) 99999-2222"));
    listaContatos.push_back(Contato("DataFlow Sistemas", "(11) 97777-3333"));

    cout << "\n--- Exibindo Lista de Contatos Registrados ---" << endl;

    // Iteração sobre o vector utilizando range-based for loop
    for (const auto& contato : listaContatos) {
        contato.imprimirNome();
        contato.imprimirTelefone();
        cout << "-----------------------------------" << endl;
    }

    cout << "\nEncerrando o programa..." << endl;
    
    // Ao sair da função main, o vector é destruído, acionando o destrutor de cada objeto
    return 0;
}