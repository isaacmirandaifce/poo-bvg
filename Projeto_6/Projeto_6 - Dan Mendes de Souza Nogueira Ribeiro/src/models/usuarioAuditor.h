#ifndef USUARIOAUDITOR
#define USUARIOAUDITOR
#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"

/**
 * @class UsuarioAuditor
 * @brief Representa o perfil de Auditoria, responsável por checar fraudes e chaves criptográficas.
 */
class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio{

public:
    UsuarioAuditor(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);

    TipoUsuario getTipoUsuario() const;
    
    void gerarRelatorio() const override;
};

#endif