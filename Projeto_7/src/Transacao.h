#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

class Transacao {
private:
    int id;
    double valor;
    std::string tipo; // Ex: "PIX", "TED"

public:
    Transacao(int id, double valor, std::string tipo);

    int getId() const;
    double getValor() const;
    std::string getTipo() const;

    void exibir() const;
};

#endif // TRANSACAO_H