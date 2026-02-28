#include "../include/funcionarioaAdministrativo.h"
#include <iostream>

// Construtor padrão
FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario("", "", "FuncionarioAdministrativo"), departamento(""), cargo("") {}

// Construtor parametrizado
FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& tipo,const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "FuncionarioAdministrativo"), departamento(departamento), cargo(cargo) {}

// Sobrescrita de gerarRelatorio
void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Funcionario Administrativo: " << nome << "\n"
              << "Departamento: " << departamento << "\n"
              << "Cargo: " << cargo << "\n";
}
