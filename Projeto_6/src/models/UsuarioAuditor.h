#ifndef USUARIO_AUDITOR_H
#define USUARIO_AUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
    private:
        std::string senhaAuditor;

    public: 
        UsuarioAuditor(int id, std::string username, std::string senha);

        bool autenticar(std::string senha) override;
        void gerarRelatorio() const override;
};

#endif