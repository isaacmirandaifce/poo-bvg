#ifndef USUARIOAUDITOR_H
#define USUARIOAUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "TipoUsuario.h"
#include <string>

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string senhaHash;
    std::string chavePublica;
    std::string escopoVarredura;

public:
    TipoUsuario tipo = TipoUsuario::AUDITOR;

    UsuarioAuditor(int id, std::string username, std::string senha,
                   std::string chavePublica, std::string escopoVarredura);

    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
};

#endif