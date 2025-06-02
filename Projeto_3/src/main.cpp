#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> listaDePessoas;

    
    Pessoa p1("Carlos", "9999-0001");
    Pessoa p2("Ana", "9999-0002");
    Pessoa p3("João", "9999-0003");

    listaDePessoas.push_back(p1);
    listaDePessoas.push_back(p2);
    listaDePessoas.push_back(p3);

   
    for (int i = 0; i < listaDePessoas.size(); i++) {
        listaDePessoas[i].imprimirNome();
        listaDePessoas[i].imprimirTelefone();
        cout << "------------------------" << endl;
    }

    return 0;
}
