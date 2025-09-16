#include "ContaPoupanca.h"
#include <iostream>
using namespace std;

ContaPoupanca::ContaPoupanca(string titular, double saldo, double taxa) 
    : Conta(titular, saldo), taxaRendimento(taxa) {}

void ContaPoupanca::sacar(double valor) {
    if(valor <= saldo) {
        saldo -= valor;
    } else {
        cout << "Saldo insuficiente." << endl;
    }
}

void ContaPoupanca::render() {
    saldo += saldo * taxaRendimento;
}

void ContaPoupanca::exibir() const {
    Conta::exibir();
    cout << "Taxa de rendimento: " << taxaRendimento << endl;
}
