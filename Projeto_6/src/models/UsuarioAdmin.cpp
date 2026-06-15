#include "UsuarioAdmin.h"
#include <iostream>

UsuarioAdmin::UsuarioAdmin(
    int id,
    const std::string& username,
    const std::string& senha
) : UsuarioAutenticavel(id, username, senha) {}

bool UsuarioAdmin::autenticar(const std::string& senhaInformada) const {
    return senhaInformada == senha;
}

std::string UsuarioAdmin::getNivelAcesso() const {
    return "Acesso total ao sistema";
}

TipoUsuario UsuarioAdmin::getTipo() const {
    return TipoUsuario::ADMIN;
}

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "Relatorio do Administrador" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Usuario: " << username << std::endl;
    std::cout << "Nivel de acesso: " << getNivelAcesso() << std::endl;
}

void UsuarioAdmin::gerenciarUsuarios() const {
    std::cout << username << " esta gerenciando usuarios do sistema." << std::endl;
}