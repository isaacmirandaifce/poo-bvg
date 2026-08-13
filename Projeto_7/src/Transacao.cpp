#include "Transacao.h"
#include <sstream>
#include <iomanip>

Transacao::Transacao(int id, double valor, const std::string& tipo)
    : id(id), valor(valor), tipo(tipo) {}

int Transacao::getId() const {
    return id;
}

double Transacao::getValor() const {
    return valor;
}

std::string Transacao::getTipo() const {
    return tipo;
}

std::string Transacao::toString() const {
    std::ostringstream oss;
    oss << "[Transacao #" << id << "] tipo=" << tipo
        << " valor=R$" << std::fixed << std::setprecision(2) << valor;
    return oss.str();
}
