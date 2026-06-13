#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"
#include "usuarioAdmin.h"

usuarioAdmin::usuarioAdmin(int id, std::string nome, std::string senha){
    this->setID(id);
    this->setUsername(nome);
    this->setSenha(senha);
};

bool usuarioAdmin::autenticar(std::string senha){

    return getSenha() == senha;
};

void usuarioAdmin::gerarRelatorio() const {

    std::cout << std::endl << "logs de modificações do sistema" << std::endl;
};

TipoUsuario usuarioAdmin::getTipoUsuario() const{

    return TipoUsuario::ADMIN;
};