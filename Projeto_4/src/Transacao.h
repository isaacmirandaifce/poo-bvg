#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

class ContaBancaria; // forward declaration

class Transacao {
private:
    double valor;
    std::string data;

public:
    Transacao(double valor, const std::string& data);

    void exibirDados() const;

    // Declaração da função amiga
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif // TRANSACAO_H
