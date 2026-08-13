#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

/**
 * @class Transacao
 * @brief Representa uma transação financeira do sistema SecureBank Pro.
 *
 * Classe de domínio utilizada para validar a genericidade de DataFilter<T>.
 * Possui um identificador, um valor monetário e um tipo de operação
 * (ex.: "PIX", "TED").
 */
class Transacao {
private:
    int id;
    double valor;
    std::string tipo;

public:
    Transacao(int id, double valor, const std::string& tipo);

    int getId() const;
    double getValor() const;
    std::string getTipo() const;

    /**
     * @brief Gera uma representação textual da transação, usada pelo
     * método processar() de DataFilter<Transacao> para impressão em log.
     */
    std::string toString() const;
};

#endif // TRANSACAO_H
