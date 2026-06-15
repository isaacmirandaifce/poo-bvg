#ifndef USUARIO_AUDITOR_H
#define USUARIO_AUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
public:
    UsuarioAuditor(int id, const std::string& username, const std::string& senha);

    bool autenticar(const std::string& senhaInformada) const override;

    std::string getNivelAcesso() const override;

    TipoUsuario getTipo() const override;

    void gerarRelatorio() const override;

    void consultarLogs() const;
};

#endif