#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario() {

    departamento = "";
    cargo = "";
}

FuncionarioAdministrativo::FuncionarioAdministrativo(
    string nome,
    string email,
    string departamento,
    string cargo)

    : Usuario(nome, email,
              "Funcionario Administrativo") {

    this->departamento = departamento;
    this->cargo = cargo;
}

void FuncionarioAdministrativo::gerarRelatorio() {

    cout << "\n===== RELATORIO FUNCIONARIO =====" << endl;

    cout << "Nome: " << nome << endl;
    cout << "Email: " << email << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}

FuncionarioAdministrativo::~FuncionarioAdministrativo() {
}