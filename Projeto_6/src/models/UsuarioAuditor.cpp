#include "UsuarioAuditor.h"
#include <iostream>

using namespace std;

UsuarioAuditor::UsuarioAuditor(
    int id,
    string username,
    string senha)
    : UsuarioAutenticavel(id, username, senha)
{
}

bool UsuarioAuditor::autenticar(string senha)
{
    return this->senha == senha;
}

void UsuarioAuditor::gerarRelatorio() const
{
    cout << "\n===== RELATORIO AUDITOR =====\n";
    cout << "Chave publica: RSA-2048\n";
    cout << "Escopo: verificacao antifraude\n";
}

TipoUsuario UsuarioAuditor::getTipo() const
{
    return TipoUsuario::AUDITOR;
}