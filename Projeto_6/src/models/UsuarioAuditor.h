#ifndef USUARIO_AUDITOR_H
#define USUARIO_AUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "../enums/TipoUsuario.h"
#include <string>

/**
 * @class UsuarioAuditor
 * @brief Perfil responsavel por checar fraudes. Seu relatorio expoe
 *        a chave de criptografia publica e o escopo de varredura.
 */
class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
private:
    static const TipoUsuario tipo;
    std::string chavePublica;
    std::string escopoVarredura;

public:
    UsuarioAuditor(int id, const std::string& username, const std::string& senha,
                   const std::string& chavePublica, const std::string& escopoVarredura);

    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;

    TipoUsuario getTipo() const;
};

#endif // USUARIO_AUDITOR_H
