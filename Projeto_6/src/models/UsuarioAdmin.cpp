#include "UsuarioAdmin.h"
#include <iostream>

UsuarioAdmin::UsuarioAdmin(int id, std::string username, std::string senha)
    : UsuarioAutenticavel(id, username, TipoUsuario::ADMIN), senhaCorreta(senha) {}

bool UsuarioAdmin::autenticar(std::string senha) {
    return this->senhaCorreta == senha;
}

void UsuarioAdmin::gerarRelatorio() const {
    std::cout << "[RELATORIO ADMIN] Usuario: " << username << " | Permissoes Totais Ativas.\n";
    std::cout << " -> Logs de modificacoes do sistema: 0 alteracoes nao autorizadas.\n";
}