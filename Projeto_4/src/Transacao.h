#pragma once
#include <string>

class ContaBancaria; // Declaração antecipada

class Transacao {
private:
    double valor;
    std::string data;

public:
    Transacao(double valor, std::string data);

    // Função amiga declarada aqui também
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};
