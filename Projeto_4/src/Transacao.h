#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

// Forward declaration para a classe ContaBancaria
class ContaBancaria;

class Transacao {
private:
    double valor;
    std::string data;

public:
    Transacao(double valor, std::string data);

    // Declaração da função amiga
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif