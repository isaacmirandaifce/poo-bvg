#include "FuncionarioAdministrativo.h"

using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string departamento, string cargo)
    : Usuario(nome, email, "Administrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() {
    cout << "--- Relatorio Administrativo ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}
