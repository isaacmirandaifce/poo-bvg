#include "UsuarioAuditor.h"
#include <iostream>

UsuarioAuditor::UsuarioAuditor(int id, std::string username, std::string senha) : UsuarioAutenticavel(id, username, TipoUsuario::AUDITOR), senhaAuditor(senha) {}

bool UsuarioAuditor::autenticar(std::string senha) {
    return this->senhaAuditor == senha;
};

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "(AUDITORIA LOG) ID: " << id << " ; User: " << username << "\n";
    std::cout << "\tChaves de Criptografica Publicas: Validadas. Escopo: Global.\n";
};
