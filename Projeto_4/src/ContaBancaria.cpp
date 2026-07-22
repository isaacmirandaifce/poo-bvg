#include "ContaBancaria.h"

using namespace std;

// Construtor parametrizado
ContaBancaria::ContaBancaria(string titular, string cpf, double saldoInicial) {
    this->titular = titular;
    this->cpf = cpf;
    this->saldo = saldoInicial;
}

void ContaBancaria::exibirDadosBasicos() {
    cout << "Titular: " << this->titular << endl;
    cout << "Saldo atual: R$ " << this->saldo << endl;
}
