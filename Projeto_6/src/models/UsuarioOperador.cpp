#include "UsuarioOperador.h"
#include <iostream>

UsuarioOperador::UsuarioOperador(int _id, std::string _username) : UsuarioAutenticavel(_id, _username) {}

bool UsuarioOperador::autenticar(std::string senha) {
    return (senha == "Op1234");
}

void UsuarioOperador::registrarAcesso(std::string recurso, std::string dataHora, int status) {
    historico.push_back(HistoricoAcessos(recurso, dataHora, status));
}

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "[AUDITORIA OPERACIONAL] Operador: " << username << " (ID: " << id << ")\n"
              << "-> HISTÓRICO BLINDADO DE SESSÃO:\n";
    if (historico.empty()) {
        std::cout << "   Nenhum registro de navegação nesta sessão.\n";
    } else {
        for (const auto& log : historico) {
            std::cout << "   - [" << log.dataHora << "] Recurso: " << log.recursoAcessado 
                      << " | HTTP Status: " << log.statusCodigo << "\n";
        }
    }
    std::cout << "--------------------------------------------------\n";
}