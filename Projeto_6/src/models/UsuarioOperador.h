#ifndef USUARIO_OPERADOR_H
#define USUARIO_OPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <string>
#include <vector>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
private:
    std::string senhaCorreta;

    // CLASSE INTERNA Oculta (Nested Class)
    class HistoricoAcessos {
    private:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;
    public:
        HistoricoAcessos(std::string recurso, std::string data, int status);
        std::string formatarLog() const;
    };

    std::vector<HistoricoAcessos> acessos;

public:
    UsuarioOperador(int id, std::string username, std::string senha);
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
    
    void registrarAcesso(std::string recurso, std::string data, int status);
};

#endif