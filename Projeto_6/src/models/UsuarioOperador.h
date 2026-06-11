#ifndef USUARIOOPERADOR_H
#define USUARIOOPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"

#include <vector>

class UsuarioOperador :
    public UsuarioAutenticavel,
    public Relatorio
{
private:

    class HistoricoAcessos
    {
    private:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

    public:
        HistoricoAcessos(
            std::string recurso,
            std::string dataHora,
            int status);

        void exibir() const;
    };

    std::vector<HistoricoAcessos> historico;

public:
    UsuarioOperador(
        int id,
        std::string username,
        std::string senha);

    void adicionarAcesso(
        std::string recurso,
        std::string dataHora,
        int status);

    bool autenticar(std::string senha) override;

    void gerarRelatorio() const override;

    TipoUsuario getTipo() const override;
};

#endif