#include "UsuarioAuditor.h"
#include <iostream>

UsuarioAuditor::UsuarioAuditor(int id, std::string username, std::string senha,
                               std::string chavePublica, std::string escopoVarredura)
    : UsuarioAutenticavel(id, username),
      senhaHash(senha),
      chavePublica(chavePublica),
      escopoVarredura(escopoVarredura) {}

bool UsuarioAuditor::autenticar(std::string senha) {
    if (senha == senhaHash) {
        std::cout << "[AUDITOR] Login bem-sucedido para: " << username << std::endl;
        return true;
    }
    std::cout << "[AUDITOR] Falha na autenticacao para: " << username << std::endl;
    return false;
}

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "\n=== RELATORIO AUDITOR ===" << std::endl;
    std::cout << "ID: " << id << " | Usuario: " << username << std::endl;
    std::cout << "Chave Publica: " << chavePublica << std::endl;
    std::cout << "Escopo de Varredura: " << escopoVarredura << std::endl;
}