#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

class ContaBancaria;

class Transacao {
private:
    double valor;
    std::string data;

public:
    Transacao(double valor, std::string data);

    // Declaração da mesma função amiga externa
    friend bool validarTransacao(ContaBancaria& conta, Transacao& transacao);
};

#endif // TRANSACAO_H