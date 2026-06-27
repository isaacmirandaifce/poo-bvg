#ifndef USUARIO_OPERADOR_H
#define USUARIO_OPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <vector>

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo = TipoUsuario::OPERADOR;

    class HistoricoAcessos {
    public:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

        HistoricoAcessos(std::string rec, std::string dt, int status)
            : recursoAcessado(rec), dataHora(dt), statusCodigo(status) {}
    };

    std::vector<HistoricoAcessos> historico;

public:
    UsuarioOperador(int _id, std::string _username);
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
    
    void registrarAcesso(std::string recurso, std::string dataHora, int status);
    
    TipoUsuario getTipo() const { return tipo; }
};

#endif