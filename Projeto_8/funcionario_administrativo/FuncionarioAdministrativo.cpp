#include "FuncionarioAdministrativo.h"
#include <iostream>

//inicializa os atributos
FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string id, string departamento)
    : Usuario(nome, id), departamento(departamento) {}

void FuncionarioAdministrativo::exibirInformacoes() const {
    Usuario::exibirInformacoes();
    cout << "Departamento: " << departamento << endl;
}
