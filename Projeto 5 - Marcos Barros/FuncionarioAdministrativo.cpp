#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo)
    : Usuario(nome, email, "FuncionarioAdministrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Funcionário: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << "\n";
}
