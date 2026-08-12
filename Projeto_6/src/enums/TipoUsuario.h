#ifndef TIPO_USUARIO_H
#define TIPO_USUARIO_H

/**
 * @enum TipoUsuario
 * @brief Enumeracao fortemente tipada (enum class) usada para
 *        identificar rapidamente o escopo de acesso de um usuario
 *        no sistema de mensageria interno, sem risco de conversao
 *        implicita indevida para int (diferente de um enum tradicional).
 */
enum class TipoUsuario {
    ADMIN,
    AUDITOR,
    OPERADOR
};

/**
 * @brief Converte o enum para uma string legivel, util para logs
 *        e para a exibicao nos relatorios em terminal.
 */
inline const char* tipoUsuarioParaTexto(TipoUsuario tipo) {
    switch (tipo) {
        case TipoUsuario::ADMIN:
            return "ADMIN";
        case TipoUsuario::AUDITOR:
            return "AUDITOR";
        case TipoUsuario::OPERADOR:
            return "OPERADOR";
    }
    return "DESCONHECIDO";
}

#endif // TIPO_USUARIO_H
