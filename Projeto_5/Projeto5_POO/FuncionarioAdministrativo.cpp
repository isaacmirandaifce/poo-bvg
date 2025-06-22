#include "FuncionarioAdministrativo.h"
#include <iostream>
using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo(string n, string e, string d, string c)
    : Usuario(n, e, "Funcionario Administrativo") {
    departamento = d;
    cargo = c;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "Funcionário: " << nome << " | Departamento: " << departamento
         << " | Cargo: " << cargo << endl;
}
