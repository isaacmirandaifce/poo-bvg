#include <iostream>
#include <vector>
#include "pessoa.h"

using namespace std;

int main (){
    vector<Pessoa> pessoas;
    int quantidade = 3;
    cout << "---- Cadastro de pessoas ----- \n";
    for (int i = 0; i< quantidade; i++){
        string nome, telefone;

        cout << "Digite o nome: ";
        getline(cin, nome);

        cout << "Digite o telefone: ";
        getline(cin, telefone);
        pessoas.emplace_back(nome, telefone);
    }
    cout << "---- Pessoas Cadastradas ------ \n";
    for (const auto& pessoa: pessoas){
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        cout << "----------------------\n";
    }
    return 0;
}