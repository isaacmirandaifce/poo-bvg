#include "Transacao.h"
#include <iostream>

Transacao::Transacao(double valor, std::string data) {
    this->valor = valor;
    this->data  = data;
}

void Transacao::exibirTransacao() const {
    std::cout << "Valor:  R$ " << this->valor << std::endl;
    std::cout << "Data:   "    << this->data  << std::endl;
}