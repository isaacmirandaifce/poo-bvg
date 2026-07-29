#include "UsuarioAdmin.h"
#include <iostream>

UsuarioAdmin::UsuarioAdmin(int id, std::string username, std::string senha, std::vector<std::string> logs)
    : UsuarioAutenticavel(id, username, senha, TipoUsuario::ADMIN), logsModificacoes(logs) {}

bool UsuarioAdmin::autenticar(std::string senha) {
    return (this->senhaHash == senha);
}

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "[RELATÓRIO ADMIN - TI] ID: " << id << " | User: " << username << " | Tipo: " << tipoToString() << "\n";
    std::cout << "--> Logs de Modificações do Sistema:\n";
    for (const auto& log : logsModificacoes) {
        std::cout << "    - " << log << "\n";
    }
    std::cout << "----------------------------------------------------\n";
}