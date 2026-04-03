#include "FuncionarioAdministrativo.h"
#include <iostream>

using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo() {}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string dep, string cargo)
    : Usuario(nome, email, "Funcionario") {
    departamento = dep;
    this->cargo = cargo;
}

void FuncionarioAdministrativo::gerarRelatorio() {
    cout << "Funcionario: " << nome << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}
