#ifndef USUARIOADMIN_H
#define USUARIOADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

class UsuarioAdmin :
    public UsuarioAutenticavel,
    public Relatorio
{
public:
    UsuarioAdmin(
        int id,
        string username,
        string senha);

    bool autenticar(string senha) override;

    void gerarRelatorio() const override;

    TipoUsuario getTipo() const override;
};

#endif