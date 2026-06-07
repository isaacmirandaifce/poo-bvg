#pragma once

#include <string>

class ContaBancaria; // forward declaration

class Transacao {
private:
    double      valor;
    std::string data;

public:
    Transacao(double valor, std::string data);

    void exibirTransacao() const;

    // Função amiga: acessa valor (private) da Transacao
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};