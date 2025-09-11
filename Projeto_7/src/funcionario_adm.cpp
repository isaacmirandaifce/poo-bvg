#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& senha, const std::string& setor)
    : UsuarioAutenticavel(nome, email, senha), setor(setor), tipo(TipoUsuario::FUNCIONARIO_ADMINISTRATIVO) {}

bool FuncionarioAdministrativo::autenticar(const std::string& tentativaSenha) const {
    return senha == tentativaSenha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nSetor: " << setor << "\n";
}

TipoUsuario FuncionarioAdministrativo::getTipo() const {
    return tipo;
}

std::string FuncionarioAdministrativo::getSetor() const {
    return setor;
}

void FuncionarioAdministrativo::setSetor(const std::string& novoSetor) {
    setor = novoSetor;
}