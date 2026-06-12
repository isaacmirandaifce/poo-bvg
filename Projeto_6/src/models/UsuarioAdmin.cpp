#include "UsuarioAdmin.h"
#include <iostream>

UsuarioAdmin::UsuarioAdmin(int id, std::string username, std::string senha) : UsuarioAutenticavel(id, username, TipoUsuario::ADMIN), senhaAdmin(senha) {}

bool UsuarioAdmin::autenticar(std::string senha) {
    return this->senhaAdmin == senha;
};

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "(ADMIN LOG) ID: " << id << " ; User: " << username << "\n";
    std::cout << "\t Logs de sistema: Rotinas de backup OK, Firewall configurado.\n";
};

