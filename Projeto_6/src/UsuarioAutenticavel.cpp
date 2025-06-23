
#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string cpf, TipoUsuario tipo, std::string senha)
    : Usuario(nome, cpf, tipo), senha(senha) {}

UsuarioAutenticavel::~UsuarioAutenticavel() {}