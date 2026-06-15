#ifndef USUARIO_OPERADOR_H
#define USUARIO_OPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>
#include <vector>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
private:
    class HistoricoAcessos {
    private:
        struct RegistroAcesso {
            std::string recursoAcessado;
            std::string dataHora;
            int statusCodigo;
        };

        std::vector<RegistroAcesso> registros;

    public:
        void adicionarAcesso(
            const std::string& recursoAcessado,
            const std::string& dataHora,
            int statusCodigo
        );

        void exibirHistorico() const;
    };

    HistoricoAcessos historico;

public:
    UsuarioOperador(int id, const std::string& username, const std::string& senha);

    bool autenticar(const std::string& senhaInformada) const override;

    std::string getNivelAcesso() const override;

    TipoUsuario getTipo() const override;

    void gerarRelatorio() const override;

    void executarOperacao(const std::string& operacao);


};

#endif