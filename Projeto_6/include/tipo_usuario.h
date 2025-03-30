#ifndef TIPO_USUARIO_H
#define TIPO_USUARIO_H

#include <string>

enum class TipoUsuario {
    ALUNO,
    PROFESSOR,
    FUNCIONARIO_ADMINISTRATIVO
};

// Função para converter TipoUsuario para string
std::string tipoUsuarioToString(TipoUsuario tipo);

#endif // TIPO_USUARIO_H
