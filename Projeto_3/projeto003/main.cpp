#include <iostream>
#include <vector>
#include <string> // Necessário para getline
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> listaDePessoas;

    // --- Inserção Automática (para popular a lista) ---
    listaDePessoas.push_back(Pessoa("Carlos Silva", "(11) 99999-1234"));
    listaDePessoas.push_back(Pessoa("Ana Souza", "(21) 98888-5678"));

    // --- Inserção Manual (Requisito: uso de std::cin) ---
    string nomeTemp, telTemp;

    cout << "--- Cadastro de Nova Pessoa ---" << endl;

    cout << "Digite o nome da pessoa: ";
    // Usamos getline para permitir nomes com sobrenome (espaços)
    getline(cin, nomeTemp);

    cout << "Digite o telefone: ";
    // Usamos getline aqui também para evitar problemas com buffer do teclado
    getline(cin, telTemp);

    // Cria o objeto com os dados do usuário e adiciona ao vetor
    Pessoa p3(nomeTemp, telTemp);
    listaDePessoas.push_back(p3);

    cout << "\n--- Lista Completa de Contatos ---" << endl;

    // Percorrendo o vector e exibindo informações
    for (size_t i = 0; i < listaDePessoas.size(); i++) {
        cout << "\n[Contato " << i + 1 << "]" << endl;
        listaDePessoas[i].imprimirNome();
        listaDePessoas[i].imprimirTelefone();
    }

    cout << "\n--- Encerrando programa ---" << endl;

    return 0;
}
