#include "UsuarioAdmin.h"
#include <iostream>

UsuarioAdmin::UsuarioAdmin(int id, std::string username, std::string senha)
    : UsuarioAutenticavel(id, username), senhaHash(senha) {}

bool UsuarioAdmin::autenticar(std::string senha) {
    if (senha == senhaHash) {
        std::cout << "[ADMIN] Login bem-sucedido para: " << username << std::endl;
        return true;
    }
    std::cout << "[ADMIN] Falha na autenticacao para: " << username << std::endl;
    return false;
}

void UsuarioAdmin::registrarModificacao(std::string log) {
    logsModificacao.push_back(log);
}

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "\n=== RELATORIO ADMIN ===" << std::endl;
    std::cout << "ID: " << id << " | Usuario: " << username << std::endl;
    std::cout << "Logs de modificacoes do sistema:" << std::endl;

    if (logsModificacao.empty()) {
        std::cout << "  Nenhuma modificacao registrada." << std::endl;
    } else {
        for (const auto& log : logsModificacao) {
            std::cout << "  - " << log << std::endl;
        }
    }
}