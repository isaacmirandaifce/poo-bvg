#include "FuncionarioAdministrativo.h"
#include <iostream>
using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo(const string& nome, const string& email, const string& departamento, const string& cargo)
    : Usuario(nome, email, "Funcionario"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "Funcionário Administrativo: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << endl;
}
