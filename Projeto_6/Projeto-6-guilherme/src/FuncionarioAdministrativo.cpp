#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario(), departamento(""), cargo("") {
    tipo = "Funcionario";
}

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email,
                                                     std::string departamento, std::string cargo)
    : Usuario(nome, email, "Funcionario"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "=== Relatório do Funcionário Administrativo ===\n"
              << "Nome: " << nome << "\n"
              << "Departamento: " << departamento << "\n"
              << "Cargo: " << cargo << "\n";
}
