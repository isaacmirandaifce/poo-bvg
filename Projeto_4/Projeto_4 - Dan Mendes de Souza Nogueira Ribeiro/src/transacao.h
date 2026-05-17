#include <iostream>
#include <string>
#include "contaBancaria.h"
#pragma once

class Transacao{
    private:
        double valor;
        std::string cpf;

    public:
        void setValor(double valor);

        void setCPF(std::string cpf);

        std::string getCPF();

        double getValor();

        friend void validarTransacao(Transacao &t, contaBancaria &c);
};

