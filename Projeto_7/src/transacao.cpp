#include "Transacao.h"
#include <iostream>

Transacao::Transacao(int id, double valor, std::string tipo)
    : id(id), valor(valor), tipo(tipo) {}

void Transacao::exibir() const {
    std::cout << "[TRANSACAO] ID: " << id
              << " | Valor: R$ " << valor
              << " | Tipo: " << tipo << std::endl;
}