#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>
#include <string>

using namespace std;

class Transacao;

class ContaBancaria {
private:
    string titular;
    string cpf;

protected:
    double saldo;

public:
    ContaBancaria(string titular, string cpf, double saldo);

    void exibirDados();

    friend bool validarTransacao(ContaBancaria &conta, Transacao &transacao);
};

#endif