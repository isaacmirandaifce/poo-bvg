#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

void exibirListaPessoas(const vector<Pessoa>& pessoas) {
    if(pessoas.empty()) {
        cout << "Nenhuma pessoa cadastrada." << endl;
        return;
    }
    
    cout << "\nLista de Pessoas:" << endl;
    cout << "-----------------" << endl;
    
    for (const Pessoa& pessoa : pessoas) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        cout << endl;
    }
}

int main() {
    try {
        vector<Pessoa> pessoas;
        
        // Adiciona algumas pessoas para teste
        pessoas.push_back(Pessoa("João Silva", "(11) 9999-8888"));
        pessoas.push_back(Pessoa("Luis Alves", "(21) 7777-6666")); 
        pessoas.push_back(Pessoa("Carla Silva", "(31) 5555-4444"));

        exibirListaPessoas(pessoas);
        
        return 0;
    }
    catch(const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }
}
