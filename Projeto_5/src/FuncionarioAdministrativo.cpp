#include "FuncionarioAdministrativo.hpp"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {
    tipo = "Funcionario Administrativo";
}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatorio do Funcionario Administrativo\n";
    std::cout << "Nome: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << "\n";
    std::cout << "----------------------\n";
}
