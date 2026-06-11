#include "UsuarioAutenticavel.h"

Usuario::Usuario(int id, string username)
{
    this->id = id;
    this->username = username;
}

Usuario::~Usuario()
{
}

string Usuario::getUsername() const
{
    return username;
}

int Usuario::getId() const
{
    return id;
}

UsuarioAutenticavel::UsuarioAutenticavel(
    int id,
    string username,
    string senha)
    : Usuario(id, username)
{
    this->senha = senha;
}

UsuarioAutenticavel::~UsuarioAutenticavel()
{
}