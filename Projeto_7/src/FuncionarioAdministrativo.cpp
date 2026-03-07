#include <iostream>
#include "../include/FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo(
    std::string nome,
    std::string senha
) : UsuarioAutenticavel(
        nome,
        TipoUsuario::FUNCIONARIO_ADMINISTRATIVO,
        senha
    ) {}

bool FuncionarioAdministrativo::autenticar(std::string senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Funcionário Administrativo ===\n";
    std::cout << "Nome: " << nome << "\n";
}