#ifndef USUARIOADMIN
#define USUARIOADMIN
#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"

/**
 * @class usuarioAdmin
 * @brief Representa o perfil de TI, responsável por logs e modificações gerais.
 */
class usuarioAdmin : public UsuarioAutenticavel, public Relatorio
{

public:
    
    /**
     * @brief Construtor da classe usuarioAdmin.
     * @param id Identificador numérico do usuário.
     * @param nome Nome de usuário (username).
     * @param senha Senha de acesso.
     */
    usuarioAdmin(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);

    TipoUsuario getTipoUsuario() const;

    void gerarRelatorio() const;
};

#endif