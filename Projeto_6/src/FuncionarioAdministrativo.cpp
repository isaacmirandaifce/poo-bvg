#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(
    std::string nome, std::string matricula, std::string senha)
    : UsuarioAutenticavel(nome, matricula, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo: " << nome << std::endl;
}
