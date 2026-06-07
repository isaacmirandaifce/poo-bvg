#pragma once

#include <string>

class Transacao; // forward declaration

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo;

public:
    ContaBancaria(std::string titular, std::string cpf, double saldo);

    void exibirDados() const;

    // Função amiga: acessa saldo (protected) e os privados da Transacao
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};