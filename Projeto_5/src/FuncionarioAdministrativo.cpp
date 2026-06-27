#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string n, std::string e, std::string t, std::string dept, std::string carg)
    : Usuario(n, e, t), departamento(dept), cargo(carg) {}

void FuncionarioAdministrativo::gerarRelatorio() {
    std::cout << "--- RELATORIO DE FUNCIONARIO ---" << std::endl;
    std::cout << "Nome: " << nome << " | Departamento: " << departamento << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
    std::cout << "--------------------------------" << std::endl;
}