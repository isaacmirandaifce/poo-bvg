#include "ContaCorrente.h"
#include <iostream>
using namespace std;

ContaCorrente::ContaCorrente(string titular, double saldo, double limite) 
    : Conta(titular, saldo), limite(limite) {}

void ContaCorrente::sacar(double valor) {
    if(valor <= saldo + limite) {
        saldo -= valor;
    } else {
        cout << "Saldo insuficiente (com limite)." << endl;
    }
}

void ContaCorrente::exibir() const {
    Conta::exibir();
    cout << "Limite: " << limite << endl;
}
