#include "Usuario.h"
#include <iostream>

Usuario::Usuario(string nome, string id) : nome(nome), id(id) {}

void Usuario::exibirInformacoes() const {
    cout << "Nome: " << nome << "\nID: " << id << endl;
}
