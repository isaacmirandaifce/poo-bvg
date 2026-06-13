#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"
#include "usuarioAuditor.h"

UsuarioAuditor::UsuarioAuditor(int id, std::string nome, std::string senha) {
    this->setID(id);
    this->setUsername(nome);
    this->setSenha(senha);
};

bool UsuarioAuditor::autenticar(std::string senha) {

    return getSenha() == senha;
};

TipoUsuario UsuarioAuditor::getTipoUsuario() const
{

    return TipoUsuario::AUDITOR;
};

void UsuarioAuditor::gerarRelatorio() const {

    std::cout << std::endl << "Relatorio de Auditoria: Chaves de criptografia publicas e escopo de varredura" << std::endl;
};