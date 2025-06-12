#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo)
    : Usuario(nome, email, "FuncionarioAdministrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Funcionario Administrativo: " << nome << "\nDepartamento: " << departamento
              << "\nCargo: " << cargo << "\n";
}
