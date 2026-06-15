#ifndef USUARIO_ADMIN_H
#define USUARIO_ADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
public:
    UsuarioAdmin(int id, const std::string& username, const std::string& senha);

    bool autenticar(const std::string& senhaInformada) const override;

    std::string getNivelAcesso() const override;

    TipoUsuario getTipo() const override;

    void gerarRelatorio() const override;

    void gerenciarUsuarios() const;
};

#endif