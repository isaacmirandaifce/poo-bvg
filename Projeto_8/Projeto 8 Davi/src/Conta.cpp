#include "Conta.h"
#include <iostream>
using namespace std;

Conta::Conta(string titular, double saldo) : titular(titular), saldo(saldo) {}

void Conta::depositar(double valor) {
    saldo += valor;
}

void Conta::exibir() const {
    cout << "Titular: " << titular << " | Saldo: " << saldo << endl;
}

string Conta::getTitular() const {
    return titular;
}

double Conta::getSaldo() const {
    return saldo;
}
