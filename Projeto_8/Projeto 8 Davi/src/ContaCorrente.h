#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
    double limite;
public:
    ContaCorrente(string titular, double saldo, double limite);
    void sacar(double valor) override;
    void exibir() const override;
};

#endif
