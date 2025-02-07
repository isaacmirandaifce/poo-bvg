#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& senha)
    : nome(nome), senha(senha) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo: " << nome << std::endl;
}

TipoUsuario FuncionarioAdministrativo::getTipo() const {
    return TipoUsuario::FUNCIONARIO_ADMINISTRATIVO;
}