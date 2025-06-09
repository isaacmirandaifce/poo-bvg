#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionario"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Nome: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << std::endl;
}