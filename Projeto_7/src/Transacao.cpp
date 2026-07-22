#include <iostream>
#include "Transacao.h"

using namespace std;

Transacao::Transacao() : id(0), valor(0.0), tipo("") {}

Transacao::Transacao(int id, double valor, string tipo)
    : id(id), valor(valor), tipo(tipo) {}

int Transacao::getId() const {
    return id;
}

double Transacao::getValor() const {
    return valor;
}

string Transacao::getTipo() const {
    return tipo;
}

void Transacao::exibir() const {
    cout << "[Transacao #" << id << "] Tipo: " << tipo
         << " | Valor: R$ " << valor << endl;
}
