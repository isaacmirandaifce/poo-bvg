#ifndef TIPOUSUARIO_H
#define TIPOUSUARIO_H

#include <string>

// Classe enumerada (enum class): categoriza os usuarios do sistema
enum class TipoUsuario {
    ALUNO,
    PROFESSOR,
    FUNCIONARIO_ADMINISTRATIVO
};

// Converte o enum para texto legivel, usado nos relatorios
inline std::string tipoUsuarioParaTexto(TipoUsuario tipo) {
    switch (tipo) {
        case TipoUsuario::ALUNO: return "Aluno";
        case TipoUsuario::PROFESSOR: return "Professor";
        case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO: return "Funcionario Administrativo";
        default: return "Desconhecido";
    }
}

#endif // TIPOUSUARIO_H
