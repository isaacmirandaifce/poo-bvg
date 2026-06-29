#ifndef USUARIO_OPERADOR_H
#define USUARIO_OPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>
#include <vector>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
    private:
        class HistoricoAcessos {
            public:
                std::string recursoAcessado;
                std::string dataHora;
                int statusCodigo;

                HistoricoAcessos(std::string recurso, std::string dh, int status);
                void exibir() const;
        };

        std::string senhaOperador;
        std::vector<HistoricoAcessos> historicoLogs;

    public:
        UsuarioOperador(int id, std::string username, std::string senha);

        bool autenticar(std::string senha) override;
        void gerarRelatorio() const override;

        void acessarRecurso(std::string recurso, std::string dh, int status);
};

#endif