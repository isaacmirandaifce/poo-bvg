#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

#include <string>
#include <iostream>

// Forward declaration da classe Transacao para que o compilador a reconheça no protótipo da friend function
class Transacao;

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo; // Permite acesso direto por subclasses (ex: contas de investimento)

public:
    // Construtor
    ContaBancaria(std::string titular, std::string cpf, double saldoInicial);

    // Exibição básica
    void exibirDados() const;

    // Declaração da função amiga que realiza a auditoria
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif // CONTA_BANCARIA_H