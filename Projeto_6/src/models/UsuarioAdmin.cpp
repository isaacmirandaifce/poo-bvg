#include "UsuarioAdmin.h"
#include <iostream>

UsuarioAdmin::UsuarioAdmin(int _id, std::string _username) : UsuarioAutenticavel(_id, _username) {}

bool UsuarioAdmin::autenticar(std::string senha) {
    return (senha == "Admin@Secure2026");
}

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "[AUDITORIA ADMIN] Usuário: " << username << " (ID: " << id << ")\n"
              << "-> LOGS DE MODIFICAÇÃO DO SISTEMA:\n"
              << "   - [08:30] Alteração de políticas de senha global.\n"
              << "   - [11:15] Revogação de token expirado do operador.\n"
              << "--------------------------------------------------\n";
}