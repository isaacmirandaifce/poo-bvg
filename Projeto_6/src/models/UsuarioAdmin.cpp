#include "UsuarioAdmin.h"
#include <iostream>

using namespace std;

UsuarioAdmin::UsuarioAdmin(
    int id,
    string username,
    string senha)
    : UsuarioAutenticavel(id, username, senha)
{
}

bool UsuarioAdmin::autenticar(string senha)
{
    return this->senha == senha;
}

void UsuarioAdmin::gerarRelatorio() const
{
    cout << "\n===== RELATORIO ADMIN =====\n";
    cout << "Logs de modificacoes do sistema\n";
    cout << "Backup realizado\n";
    cout << "Permissoes atualizadas\n";
}

TipoUsuario UsuarioAdmin::getTipo() const
{
    return TipoUsuario::ADMIN;
}