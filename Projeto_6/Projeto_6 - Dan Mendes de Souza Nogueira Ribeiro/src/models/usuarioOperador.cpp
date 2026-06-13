#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"
#include "usuarioOperador.h"

UsuarioOperador::UsuarioOperador(int id, std::string nome, std::string senha){
    this->setID(id);
    this->setUsername(nome);
    this->setSenha(senha);
};

bool UsuarioOperador::autenticar(std::string senha){

    return getSenha() == senha;
};

TipoUsuario UsuarioOperador::getTipoUsuario() const
{

    return TipoUsuario::OPERADOR;
};

void UsuarioOperador::gerarRelatorio() const{

    std::cout << std::endl << "log" << std::endl;
};