#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

// Forward declaration da classe ContaBancaria
class ContaBancaria;

class Transacao {
private:
    double valor;
    std::string data;

public:
    // Construtor
    Transacao(double valor, std::string data);

    // A mesma função precisa ser amiga desta classe também para ler o 'valor'
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif