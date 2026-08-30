#include "UsuarioAutenticavel.h"

std::string UsuarioAutenticavel::getTipoString() const {
    switch (tipo) {
        case TipoUsuario::ADMIN: return "ADMIN";
        case TipoUsuario::AUDITOR: return "AUDITOR";
        case TipoUsuario::OPERADOR: return "OPERADOR";
        default: return "DESCONHECIDO";
    }
}