#include "UsuarioAdmin.h"
#include <iostream>

const TipoUsuario UsuarioAdmin::tipo = TipoUsuario::ADMIN;

UsuarioAdmin::UsuarioAdmin(int id, const std::string& username, const std::string& senha)
    : UsuarioAutenticavel(id, username, senha) {
}

bool UsuarioAdmin::autenticar(std::string senha) {
    return gerarHash(senha) == senhaHash;
}

void UsuarioAdmin::registrarModificacao(const std::string& descricao) {
    logsModificacoes.push_back(descricao);
}

TipoUsuario UsuarioAdmin::getTipo() const {
    return tipo;
}

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "\n===== Relatorio [" << tipoUsuarioParaTexto(tipo) << "] =====\n";
    std::cout << "Usuario: " << username << " (ID: " << id << ")\n";
    std::cout << "Logs de modificacoes do sistema (" << logsModificacoes.size() << "):\n";

    if (logsModificacoes.empty()) {
        std::cout << "  - Nenhuma modificacao registrada nesta sessao.\n";
    } else {
        for (const auto& log : logsModificacoes) {
            std::cout << "  - " << log << "\n";
        }
    }
    std::cout << "=====================================\n";
}
