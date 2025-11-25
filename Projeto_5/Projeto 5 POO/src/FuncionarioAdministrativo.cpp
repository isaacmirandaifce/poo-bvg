#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario("", "", "Funcionario"), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome,
                                                     const std::string& email,
                                                     const std::string& departamento,
                                                     const std::string& cargo)
    : Usuario(nome, email, "Funcionario"),
      departamento(departamento),
      cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "[Funcionario] Nome: " << nome
              << " | Departamento: " << departamento
              << " | Cargo: " << cargo << std::endl;
}
