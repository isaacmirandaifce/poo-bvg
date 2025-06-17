#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string depto, std::string cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(depto), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "--- Relatorio de Funcionario Administrativo ---" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
    std::cout << "--------------------------------------------" << std::endl << std::endl;
}