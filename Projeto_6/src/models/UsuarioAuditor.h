#ifndef USUARIOAUDITOR_H
#define USUARIOAUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

class UsuarioAuditor :
    public UsuarioAutenticavel,
    public Relatorio
{
public:
    UsuarioAuditor(
        int id,
        string username,
        string senha);

    bool autenticar(string senha) override;

    void gerarRelatorio() const override;

    TipoUsuario getTipo() const override;
};

#endif