#ifndef USUARIOADMIN_H
#define USUARIOADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "TipoUsuario.h"
#include <iostream>

class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
public:
    UsuarioAdmin(int id, std::string user) : UsuarioAutenticavel(id, user) {}
    
    bool autenticar(std::string senha) override {
        return senha == "admin123";
    }

    void gerarRelatorio() const override {
        std::cout << "[Relatorio ADMIN] Logs de modificacoes do sistema gerados.\n";
    }
};

#endif
