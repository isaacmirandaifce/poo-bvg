#include <iostream>
#include <vector>
#include "Contato.h"

using namespace std;

int main() {
    cout << "--- CRM Enterprise: Inicializando Modulo B2B ---\n" << endl;

    // Criando o container dinamico de contatos
    vector<Contato> contatos;

    /* 
     * DICA DE PERFORMANCE: O reserve(3) aloca memoria previa para 3 itens.
     * Isso evita realocacoes do vector sob demanda durante os push_back(),
     * o que impediria chamadas prematuras do nosso log do destrutor.
     */
    contatos.reserve(3);

    // Instanciando 3 clientes corporativos B2B
    contatos.push_back(Contato("TechCorp SA", "+55 11 9999-8888"));
    contatos.push_back(Contato("Inova Solutions", "+55 21 7777-6666"));
    contatos.push_back(Contato("Global Logistics", "+55 31 5555-4444"));

    cout << "\n--- Lista de Contatos Cadastrados ---\n";
    
    // Iteracao utilizando foreach moderno do C++ (range-based for loop)
    for (const auto& contato : contatos) {
        contato.imprimirNome();
        contato.imprimirTelefone();
        cout << "-----------------------------------\n";
    }

    cout << "\nEncerrando o sistema e limpando memoria...\n" << endl;

    return 0; // Ao retornar 0, o 'vector' sai de escopo e aciona os destrutores!
}