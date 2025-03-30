#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "FUNCIONARIO_ADMINISTRATIVO", senha), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nDepartamento: " << departamento << "\nCargo: " << cargo << "\n";
}

bool FuncionarioAdministrativo::autenticar(const std::string& senhaTentativa) {
    return senhaTentativa == senha;
}
