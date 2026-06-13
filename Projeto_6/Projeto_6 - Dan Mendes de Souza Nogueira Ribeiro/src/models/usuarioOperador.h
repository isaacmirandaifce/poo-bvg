#ifndef USUARIOOPERADOR
#define USUARIOOPERADOR
#include <iostream>
#include <string>
#include <vector>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio{

private:
class HistoricoAcessos {
    private:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

    public:

    HistoricoAcessos(std::string recursoAcessado, std::string dataHora, int statuscodigo);

    std::string getRecursoAcessado() const;
    std::string getDataHora() const ;
    int getStatusCodigo() const;

    void mostrarDados() const;
};

std::vector<HistoricoAcessos> acessos;

public: 

    UsuarioOperador(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);

    TipoUsuario getTipoUsuario() const;

    void gerarRelatorio() const;

    void registrarAcesso(std::string recurso, std::string dataHora, int status);

    
};

#endif