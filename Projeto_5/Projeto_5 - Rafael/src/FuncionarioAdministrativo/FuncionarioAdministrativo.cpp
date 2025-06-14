#include "FuncionarioAdministrativo.h"
#include <iostream>
using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string tipo, string departamento, string cargo)
    : Usuario(nome, email, tipo), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() {
    cout << "=== FUNCIONARIO ADMINISTRATIVO ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl << endl;
}