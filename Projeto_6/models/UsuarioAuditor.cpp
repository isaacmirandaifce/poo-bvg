#include "UsuarioAuditor.h"
#include <iostream>

UsuarioAuditor::UsuarioAuditor(int id, std::string username, std::string senha, std::string chave, std::string escopo)
    : UsuarioAutenticavel(id, username, senha, TipoUsuario::AUDITOR), chaveCriptografiaPublica(chave), escopoVarredura(escopo) {}

bool UsuarioAuditor::autenticar(std::string senha) {
    return (this->senhaHash == senha);
}

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "[RELATÓRIO AUDITOR - COMPLIANCE] ID: " << id << " | User: " << username << " | Tipo: " << tipoToString() << "\n";
    std::cout << "--> Chave de Criptografia Pública: " << chaveCriptografiaPublica << "\n";
    std::cout << "--> Escopo de Varredura Antifraude: " << escopoVarredura << "\n";
    std::cout << "----------------------------------------------------\n";
}