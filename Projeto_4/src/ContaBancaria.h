#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>
#include <iostream>

class Transacao;

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo;

public:
    // Construtor parametrizado
    ContaBancaria(std::string titular, std::string cpf, double saldoInicial);

    void exibirDadosBasicos();

    // Funcao amiga: precisa de acesso intimo ao saldo (protected) para auditar
    // a transacao sem expor getters/setters publicos para o resto do sistema.
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif // CONTABANCARIA_H
