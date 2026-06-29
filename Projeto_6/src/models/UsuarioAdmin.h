#ifndef USUARIO_ADMIN_H
#define USUARIO_ADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>

class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
    private:
        std::string senhaAdmin;

    public:
        UsuarioAdmin(int id, std::string username, std::string senha);

        bool autenticar(std::string senha) override;
        void gerarRelatorio() const override;
};

#endif