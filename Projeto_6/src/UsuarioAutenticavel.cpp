#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(conststd::string& nome,
const std::string& email,
TipoUsuario tipo,
const std::string& senha): Usuario(nome, email, tipo), senha(senha) {}