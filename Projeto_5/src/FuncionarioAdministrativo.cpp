#include <iostream>
#include "FuncionarioAdministrativo.h"

using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string departamento, string cargo)
    : Usuario(nome, email, "FuncionarioAdministrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "[Relatorio de Funcionario Administrativo]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}
