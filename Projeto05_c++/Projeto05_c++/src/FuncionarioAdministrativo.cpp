#include "../include/FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatorio do Funcionario Administrativo:\n"
              << "Nome: " << nome << "\n"
              << "Departamento: " << departamento << "\n"
              << "Cargo: " << cargo << "\n";
}

