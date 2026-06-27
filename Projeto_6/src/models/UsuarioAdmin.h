#ifndef USUARIO_ADMIN_H
#define USUARIO_ADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo = TipoUsuario::ADMIN;
public:
    UsuarioAdmin(int _id, std::string _username);
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
    TipoUsuario getTipo() const { return tipo; }
};

#endif