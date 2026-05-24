#include "Transacao.h"

Transacao::Transacao(int id, double valor, std::string tipo) {
    this->id = id;
    this->valor = valor;
    this->tipo = tipo;
}

int Transacao::getId() const {
    return id;
}

double Transacao::getValor() const {
    return valor;
}

std::string Transacao::getTipo() const {
    return tipo;
}