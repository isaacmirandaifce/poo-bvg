#ifndef USUARIOADMIN_H
#define USUARIOADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "TipoUsuario.h"
#include <string>
#include <vector>

class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
private:
    std::string senhaHash;
    std::vector<std::string> logsModificacao;

public:
    TipoUsuario tipo = TipoUsuario::ADMIN;

    UsuarioAdmin(int id, std::string username, std::string senha);

    bool autenticar(std::string senha) override;
    void registrarModificacao(std::string log);
    void gerarRelatorio() const override;
};

#endif