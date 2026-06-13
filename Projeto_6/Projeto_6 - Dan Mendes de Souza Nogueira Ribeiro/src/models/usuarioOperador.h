#ifndef USUARIOOPERADOR
#define USUARIOOPERADOR
#include <iostream>
#include <string>
#include <vector>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"

/**
 * @class UsuarioOperador
 * @brief Representa um funcionário de retaguarda, ocultando o histórico de acessos.
 */
class UsuarioOperador : public UsuarioAutenticavel, public Relatorio
{

private:
    /**
     * @class HistoricoAcessos
     * @brief Classe interna e privada para encapsular os dados de navegação do operador.
     */
    class HistoricoAcessos
    {
    private:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

    public:
        HistoricoAcessos(std::string recursoAcessado, std::string dataHora, int statuscodigo);

        std::string getRecursoAcessado() const;
        std::string getDataHora() const;
        int getStatusCodigo() const;

        void mostrarDados() const;
    };

    std::vector<HistoricoAcessos> acessos;

public:
    UsuarioOperador(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);

    TipoUsuario getTipoUsuario() const;

    void gerarRelatorio() const;

    /**
     * @brief Registra um novo acesso na lista de históricos oculta.
     * @param recurso O nome do recurso acessado.
     * @param dataHora A data e hora da ocorrência.
     * @param status O código de status da operação (ex: 200, 403).
     */
    void registrarAcesso(std::string recurso, std::string dataHora, int status);
};

#endif