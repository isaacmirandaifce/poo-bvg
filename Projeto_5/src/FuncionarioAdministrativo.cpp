#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo:" << std::endl;
    std::cout << "Nome: " << nome << ", Departamento: " << departamento << ", Cargo: " << cargo << std::endl;
}
