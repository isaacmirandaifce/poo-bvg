#include "UsuarioAuditor.h"
#include <iostream>

UsuarioAuditor::UsuarioAuditor(int _id, std::string _username) : UsuarioAutenticavel(_id, _username) {}

bool UsuarioAuditor::autenticar(std::string senha) {
    return (senha == "Audit#Master!99");
}

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "[AUDITORIA ANTI-FRAUDE] Auditor: " << username << "\n"
              << "-> ESCOPO DE VARREDURA: Transações Pix > R$ 50.000,00\n"
              << "-> CHAVE PÚBLICA DE CRIPTOGRAFIA ATIVA: 0x7F3A...B92C\n"
              << "--------------------------------------------------\n";
}