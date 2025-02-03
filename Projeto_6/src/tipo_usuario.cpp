#include "tipo_usuario.h"

std::string tipoUsuarioToString(TipoUsuario tipo) {
    switch (tipo) {
        case TipoUsuario::ALUNO:
            return "Aluno";
        case TipoUsuario::PROFESSOR:
            return "Professor";
        case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO:
            return "Funcionario Administrativo";
        default:
            return "Tipo Desconhecido";
    }
}
