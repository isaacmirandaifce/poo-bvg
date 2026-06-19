#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

#include <string>

class Transacao; // forward declaration

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo;

public:
    ContaBancaria(const std::string& titular, const std::string& cpf, double saldoInicial);

    void exibirDados() const;

    // Declaração da função amiga
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif // CONTA_BANCARIA_H
