#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento("N/A"), cargo("N/A") { tipo = "Funcionario"; }

FuncionarioAdministrativo::FuncionarioAdministrativo(const string &nome, const string &email, const string &departamento, const string &cargo)
    : Usuario(nome, email, "Funcionario"), departamento(departamento), cargo(cargo) {}

FuncionarioAdministrativo::~FuncionarioAdministrativo() {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "---- Relatorio Funcionario ----" << endl;
    cout << "Nome: " << nome << " | Departamento: " << departamento << " | Cargo: " << cargo << endl;
}

string FuncionarioAdministrativo::getDepartamento() const { return departamento; }
string FuncionarioAdministrativo::getCargo() const { return cargo; }