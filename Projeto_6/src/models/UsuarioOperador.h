#ifndef USUARIO_OPERADOR_H
#define USUARIO_OPERADOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include "../enums/TipoUsuario.h"
#include <string>
#include <vector>

/**
 * @class UsuarioOperador
 * @brief Representa o funcionario do caixa/retaguarda.
 *
 * Para evitar vazamento de dados confidenciais de navegacao, o
 * historico de acessos e modelado como uma CLASSE INTERNA PRIVADA
 * (HistoricoAcessos). Por ser privada, nenhum codigo externo consegue
 * enxergar o tipo HistoricoAcessos nem manipular seus objetos
 * diretamente -- o unico ponto de exposicao controlado dos dados e o
 * metodo polimorfico gerarRelatorio().
 */
class UsuarioOperador : public UsuarioAutenticavel, public Relatorio {
private:
    static const TipoUsuario tipo;

    /**
     * @class HistoricoAcessos
     * @brief Classe interna (nested class) privada de UsuarioOperador.
     *
     * Totalmente encapsulada: so existe dentro do escopo de
     * UsuarioOperador e so pode ser criada/gerenciada pela classe
     * externa, garantindo isolamento total dos dados sensiveis de
     * navegacao do operador.
     */
    class HistoricoAcessos {
    private:
        std::string recursoAcessado;
        std::string dataHora;
        int statusCodigo;

    public:
        HistoricoAcessos(const std::string& recursoAcessado, const std::string& dataHora, int statusCodigo);

        const std::string& getRecursoAcessado() const;
        const std::string& getDataHora() const;
        int getStatusCodigo() const;
    };

    // A classe externa gerencia essa estrutura internamente; a lista
    // de historico nunca e exposta como um todo para fora da classe.
    std::vector<HistoricoAcessos> historico;

public:
    UsuarioOperador(int id, const std::string& username, const std::string& senha);

    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;

    // Unico ponto de entrada para adicionar um registro ao historico
    // oculto -- nao existe getter que devolva a lista completa.
    void registrarAcesso(const std::string& recursoAcessado, const std::string& dataHora, int statusCodigo);

    TipoUsuario getTipo() const;
};

#endif // USUARIO_OPERADOR_H
