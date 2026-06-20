#include "UsuarioOperador.h"
#include <iostream>

UsuarioOperador::UsuarioOperador(int id, std::string username, std::string senha)
    : UsuarioAutenticavel(id, username), senhaHash(senha) {}

bool UsuarioOperador::autenticar(std::string senha) {
    if (senha == senhaHash) {
        std::cout << "[OPERADOR] Login bem-sucedido para: " << username << std::endl;
        return true;
    }
    std::cout << "[OPERADOR] Falha na autenticacao para: " << username << std::endl;
    return false;
}

// Escopo duplo: UsuarioOperador::HistoricoAcessos sendo usado aqui
void UsuarioOperador::registrarAcesso(std::string recurso, std::string dataHora, int status) {
    historico.push_back(UsuarioOperador::HistoricoAcessos(recurso, dataHora, status));
}

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "\n=== RELATORIO OPERADOR ===" << std::endl;
    std::cout << "ID: " << id << " | Usuario: " << username << std::endl;
    std::cout << "Historico de Acessos:" << std::endl;

    if (historico.empty()) {
        std::cout << "  Nenhum acesso registrado." << std::endl;
    } else {
        for (const auto& h : historico) {
            std::cout << "  Recurso: " << h.recursoAcessado
                      << " | Data/Hora: " << h.dataHora
                      << " | Status: " << h.statusCodigo << std::endl;
        }
    }
}