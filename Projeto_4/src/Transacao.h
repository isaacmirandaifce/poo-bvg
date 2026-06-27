#pragma once
#include <iostream>
#include <string>
#include "ContaBancaria.h"

class Transacao{
    private: 
    double valor;
    std::string data;

    public:
    Transacao(double v, std::string d){
        valor = v;
        data = d;
    }

    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};