#include "UsuarioAuditor.h"
#include <iostream>

UsuarioAuditor::UsuarioAuditor(int id, std::string username, std::string senha, std::string chave, std::string escopo)
    : UsuarioAutenticavel(id, username, TipoUsuario::AUDITOR), 
      senhaCorreta(senha), 
      chavePublica(chave), 
      escopoVarredura(escopo) {}

bool UsuarioAuditor::autenticar(std::string senha) {
    return this->senhaCorreta == senha;
}

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "[RELATORIO AUDITOR] Usuario: " << username << " | Permissao: " << getTipoString() << "\n";
    std::cout << " -> Chave de Criptografia Publica: " << chavePublica << "\n";
    std::cout << " -> Escopo de Varredura Antifraude: " << escopoVarredura << "\n";
    std::cout << " -> Status: Sem anomalias de fraude detectadas no ciclo atual.\n";
}