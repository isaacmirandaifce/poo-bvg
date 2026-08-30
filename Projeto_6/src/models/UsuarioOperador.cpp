#include "UsuarioOperador.h"
#include <iostream>

// ---------------------------------------------------------
// Implementação da Classe Interna (Nested Class)
// ---------------------------------------------------------
UsuarioOperador::HistoricoAcessos::HistoricoAcessos(std::string recurso, std::string data, int status)
    : recursoAcessado(recurso), dataHora(data), statusCodigo(status) {}

std::string UsuarioOperador::HistoricoAcessos::formatarLog() const {
    return "[" + dataHora + "] Recurso: " + recursoAcessado + " | Status: " + std::to_string(statusCodigo);
}

// ---------------------------------------------------------
// Implementação da Classe Externa (Operador)
// ---------------------------------------------------------
UsuarioOperador::UsuarioOperador(int id, std::string username, std::string senha)
    : UsuarioAutenticavel(id, username, TipoUsuario::OPERADOR), senhaCorreta(senha) {}

bool UsuarioOperador::autenticar(std::string senha) {
    return this->senhaCorreta == senha;
}

void UsuarioOperador::registrarAcesso(std::string recurso, std::string data, int status) {
    acessos.push_back(HistoricoAcessos(recurso, data, status));
}

void UsuarioOperador::gerarRelatorio() const {
    std::cout << "[RELATORIO OPERADOR] Usuario: " << username << " | Historico de Acessos:\n";
    if (acessos.empty()) {
        std::cout << " -> Nenhum acesso registrado.\n";
    } else {
        for (const auto& acesso : acessos) {
            std::cout << " -> " << acesso.formatarLog() << "\n";
        }
    }
}