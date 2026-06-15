#include "UsuarioAuditor.h"
#include <iostream>

UsuarioAuditor::UsuarioAuditor(
    int id,
    const std::string& username,
    const std::string& senha
) : UsuarioAutenticavel(id, username, senha) {}

bool UsuarioAuditor::autenticar(const std::string& senhaInformada) const {
    return senhaInformada == senha;
}

std::string UsuarioAuditor::getNivelAcesso() const {
    return "Acesso de auditoria e consulta de logs";
}

TipoUsuario UsuarioAuditor::getTipo() const {
    return TipoUsuario::AUDITOR;
}

void UsuarioAuditor::gerarRelatorio() const {
    std::cout << "Relatorio do Auditor" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Usuario: " << username << std::endl;
    std::cout << "Nivel de acesso: " << getNivelAcesso() << std::endl;
}

void UsuarioAuditor::consultarLogs() const {
    std::cout << username << " esta consultando logs de seguranca." << std::endl;
}