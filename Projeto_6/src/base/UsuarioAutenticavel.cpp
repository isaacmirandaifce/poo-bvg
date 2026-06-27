#include "UsuarioAutenticavel.h"

Usuario::Usuario(int _id, std::string _username) 
    : id(_id), username(_username) {}

UsuarioAutenticavel::UsuarioAutenticavel(int _id, std::string _username) 
    : Usuario(_id, _username) {}