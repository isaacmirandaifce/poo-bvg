#ifndef USUARIO_AUDITOR_H
#define USUARIO_AUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string chaveCriptografiaPublica;
    std::string escopoVarredura;

public:
    UsuarioAuditor(int id, std::string username, std::string senha, std::string chave, std::string escopo);

    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
};

#endif // USUARIO_AUDITOR_H