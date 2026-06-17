#include <iostream>
#include <vector>
#include "Contato.h"

using namespace std;

int main() {
    // Container dinamico para armazenar os contatos de clientes corporativos
    vector<Contato> contatos;

    // Instanciando contatos e adicionando ao vector com push_back
    contatos.push_back(Contato("Ana Souza", "(11) 91234-5678"));
    contatos.push_back(Contato("Bruno Lima", "(21) 99876-5432"));
    contatos.push_back(Contato("Carla Mendes", "(31) 98765-4321"));

    cout << "===== Lista de Contatos CRM =====" << endl;

    // Percorrendo o vector e exibindo os dados de cada contato
    for (size_t i = 0; i < contatos.size(); i++) {
        cout << "--- Contato " << (i + 1) << " ---" << endl;
        contatos[i].imprimirNome();
        contatos[i].imprimirTelefone();
    }

    return 0;
}
