#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : UsuarioAutenticavel(), departamento(""), cargo(""), senhaHash(0) {
    tipo = TipoUsuario::FUNCIONARIO_ADMINISTRATIVO;
}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                                                     const std::string& departamento, const std::string& cargo)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO), departamento(departamento), cargo(cargo), senhaHash(0) {}

void FuncionarioAdministrativo::setSenha(const std::string& senha) {
    senhaHash = UsuarioAutenticavel::hashSenha(senha);
}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return senhaHash != 0 && senhaHash == UsuarioAutenticavel::hashSenha(senha);
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "[Funcionario] Nome: " << nome << " | Departamento: " << departamento
              << " | Cargo: " << cargo << std::endl;
}
