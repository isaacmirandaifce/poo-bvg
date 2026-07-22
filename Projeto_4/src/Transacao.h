#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <iostream>

class ContaBancaria;

class Transacao {
private:
    double valor;
    std::string data;

public:
    // Construtor parametrizado
    Transacao(double valor, std::string data);

    // Funcao amiga: declarada aqui para que o modulo de auditoria possa
    // ler o valor da transacao sem precisar de getters publicos.
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif // TRANSACAO_H
