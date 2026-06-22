#include <iostream>
#include <vector>
#include "Contato.h"


using namespace std;
 
int main() {
    cout << "===== SISTEMA CRM - MODULO DE CONTATOS =====" << endl;
    cout << endl;
 
    // Cria o vector de objetos Contato
    vector<Contato> contatos;
 
    // Instanciar 3 contatos usando push_back()
    cout << "--- Adicionando Contatos ---" << endl;
    contatos.push_back(Contato("Empresa A - Halef Alves", "+55 (85) 98765-4321"));
    contatos.push_back(Contato("Empresa B - Gabriel Uaren", "+55 (85) 99876-5432"));
    contatos.push_back(Contato("Empresa C - Luana Laura", "+55 (85) 97654-3210"));
 
    cout << endl;
    cout << "- Listando Contatos Armazenados -" << endl;
    cout << endl;
 
    // Iterar sobre o vector e imprimir dados formatados
    for (int i = 0; i < contatos.size(); i++) {
        cout << "[Contato " << (i + 1) << "]" << endl;
        contatos[i].imprimirNome();
        contatos[i].imprimirTelefone();
        cout << endl;
    }
 
    cout << "== FIM DO PROGRAMA ==" << endl;
 
    // Destrutores chamados automaticamente ao final do programa
    return 0;
}