#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <iostream>
#include <string>

using namespace std;

class ContaBancaria;

class Transacao {
private:
    double valor;
    string data;

public:
    Transacao(double valor, string data);

    friend bool validarTransacao(ContaBancaria &conta, Transacao &transacao);
};

bool validarTransacao(ContaBancaria &conta, Transacao &transacao);

#endif