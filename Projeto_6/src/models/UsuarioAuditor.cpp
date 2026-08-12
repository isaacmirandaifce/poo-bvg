#include "UsuarioAuditor.h"
#include <iostream>

const TipoUsuario UsuarioAuditor::tipo = TipoUsuario::AUDITOR;

UsuarioAuditor::UsuarioAuditor(int id, const std::string& username, const std::string& senha,
                               const std::string& chavePublica, const std::string& escopoVarredura)
    : UsuarioAutenticavel(id, username, senha),
      chavePublica(chavePublica),
      escopoVarredura(escopoVarredura) {
}

bool UsuarioAuditor::autenticar(std::string senha) {
    return gerarHash(senha) == senhaHash;
}

TipoUsuario UsuarioAuditor::getTipo() const {
    return tipo;
}

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "\n===== Relatorio [" << tipoUsuarioParaTexto(tipo) << "] =====\n";
    std::cout << "Usuario: " << username << " (ID: " << id << ")\n";
    std::cout << "Chave de criptografia publica: " << chavePublica << "\n";
    std::cout << "Escopo de varredura: " << escopoVarredura << "\n";
    std::cout << "=====================================\n";
}
