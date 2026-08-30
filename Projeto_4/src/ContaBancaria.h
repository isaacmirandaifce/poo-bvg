#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

// Forward declaration para a classe Transacao
class Transacao;

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo;

public:
    ContaBancaria(std::string titular, std::string cpf, double saldo);
    void exibirDados() const;

    // Declaração da função amiga
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif