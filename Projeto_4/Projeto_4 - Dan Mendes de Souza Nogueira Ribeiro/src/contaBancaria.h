#include <iostream>
#include <string>
#include "transacao.h"
#pragma once


class contaBancaria {
    private:
        
        std::string titular;
        std::string cpf;

    protected:
        double saldo;

    public:
        
        contaBancaria();

        ~contaBancaria();

        void setTitular(std::string nome);

        void setCPF(std::string cpf);

        void setSaldo(double saldo);

        std::string getTitular();

        std::string getCPF();

        double getSaldo();

        friend void validarTransacao(Transacao &t, contaBancaria &c);
};