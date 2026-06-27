#ifndef USUARIO_AUDITOR_H
#define USUARIO_AUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo = TipoUsuario::AUDITOR;
public:
    UsuarioAuditor(int _id, std::string _username);
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
    TipoUsuario getTipo() const { return tipo; }
};

#endif