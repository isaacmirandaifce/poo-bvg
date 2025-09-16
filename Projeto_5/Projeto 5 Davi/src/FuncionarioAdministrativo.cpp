#include "FuncionarioAdministrativo.h"
#include <iostream>
using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo() {}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string departamento, string cargo)
    : Usuario(nome, email), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "Funcionário Administrativo: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}
