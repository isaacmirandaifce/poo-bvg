#ifndef CONTA_H
#define CONTA_H

#include <string>
using namespace std;

class Conta {
protected:
    string titular;
    double saldo;
public:
    Conta(string titular, double saldo);
    virtual ~Conta() {}
    virtual void sacar(double valor) = 0;
    virtual void depositar(double valor);
    virtual void exibir() const;
    string getTitular() const;
    double getSaldo() const;
};

#endif
