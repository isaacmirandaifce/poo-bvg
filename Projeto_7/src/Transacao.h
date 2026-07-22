#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

// Classe de dominio 1: representa uma transacao financeira do SecureBank Pro.
class Transacao {
private:
    int id;
    double valor;
    std::string tipo; // "PIX", "TED"

public:
    Transacao();
    Transacao(int id, double valor, std::string tipo);

    int getId() const;
    double getValor() const;
    std::string getTipo() const;

    void exibir() const;
};

#endif // TRANSACAO_H
