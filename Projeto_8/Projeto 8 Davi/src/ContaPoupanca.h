#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {
    double taxaRendimento;
public:
    ContaPoupanca(string titular, double saldo, double taxa);
    void sacar(double valor) override;
    void render();
    void exibir() const override;
};

#endif
