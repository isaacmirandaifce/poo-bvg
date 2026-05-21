#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <iostream>
#include <string>
using namespace std;

struct Transacao {
    int id;
    double valor;
    string tipo;
};

void exibirTransacao(Transacao t);

#endif