#include <iostream>
#include <string>
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
};