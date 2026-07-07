#include <iostream>
#include <vector>
#include "Contato.h"

using namespace std;

int main() {
    // Criando o container dinamico exigido na Fase 2
    vector<Contato> listaContatos;

    // Instanciando 3 contatos corporativos
    listaContatos.push_back(Contato("Empresa Alfa", "11999991111"));
    listaContatos.push_back(Contato("Tech Beta", "21988882222"));
    listaContatos.push_back(Contato("Gama Solutions", "31977773333"));

    cout << "--- Lista de Contatos B2B ---\n";

    // Laco de repeticao para percorrer o vector e imprimir os dados
    for (int i = 0; i < listaContatos.size(); i++) {
        listaContatos[i].imprimirNome();
        listaContatos[i].imprimirTelefone();
        cout << "---------------------------\n";
    }

    return 0;
}
