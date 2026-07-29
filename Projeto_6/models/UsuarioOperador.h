#ifndef USUARIO_OPERADOR_H
#define USUARIO_OPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>
#include <vector>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
public:
    // Classe Interna (Nested Class) altamente encapsulada
    class HistoricoAcessos {
    private:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

    public:
        HistoricoAcessos(std::string recurso, std::string dataHora, int status);
        void exibirDetalhes() const;
    };

private:
    std::string departamentoRetaguarda;
    std::vector<HistoricoAcessos> historicoSessoes;

public:
    UsuarioOperador(int id, std::string username, std::string senha, std::string depto);

    void adicionarHistorico(std::string recurso, std::string dataHora, int status);
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
};

#endif // USUARIO_OPERADOR_H