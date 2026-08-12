#ifndef USUARIO_ADMIN_H
#define USUARIO_ADMIN_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "../enums/TipoUsuario.h"
#include <string>
#include <vector>

/**
 * @class UsuarioAdmin
 * @brief Perfil responsavel pela TI. Herda o contrato de login de
 *        UsuarioAutenticavel e assina o contrato Relatorio.
 */
class UsuarioAdmin : public UsuarioAutenticavel, public Relatorio {
private:
    static const TipoUsuario tipo;
    std::vector<std::string> logsModificacoes;

public:
    UsuarioAdmin(int id, const std::string& username, const std::string& senha);

    // Sobrescrita obrigatoria do metodo virtual puro herdado.
    bool autenticar(std::string senha) override;

    // Implementacao do contrato da interface Relatorio.
    void gerarRelatorio() const override;

    void registrarModificacao(const std::string& descricao);
    TipoUsuario getTipo() const;
};

#endif // USUARIO_ADMIN_H
