#ifndef USUARIOOPERADOR_H
#define USUARIOOPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "TipoUsuario.h"
#include <string>
#include <vector>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
private:
    std::string senhaHash;

    // Classe interna privada — dados de navegação totalmente encapsulados
    class HistoricoAcessos {
    public:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

        HistoricoAcessos(std::string recurso, std::string dataHora, int status)
            : recursoAcessado(recurso), dataHora(dataHora), statusCodigo(status) {}
    };

    std::vector<HistoricoAcessos> historico;

public:
    TipoUsuario tipo = TipoUsuario::OPERADOR;

    UsuarioOperador(int id, std::string username, std::string senha);

    bool autenticar(std::string senha) override;
    void registrarAcesso(std::string recurso, std::string dataHora, int status);
    void gerarRelatorio() const override;
};

#endif