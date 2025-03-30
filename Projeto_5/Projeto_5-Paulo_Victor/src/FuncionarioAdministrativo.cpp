#include "../include/FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                                                     const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatario do Funcionario Administrativo\n";
    std::cout << "Nome: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << "\n";
}
