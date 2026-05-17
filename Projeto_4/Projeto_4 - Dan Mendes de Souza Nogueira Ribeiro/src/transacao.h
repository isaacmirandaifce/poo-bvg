#ifndef Trans_h
#define Trans_h
#include<iostream>
#include <string>

class contaBancaria;
class Transacao{
    private:
        double valor;
        std::string cpf;

    public:
        Transacao();

        ~Transacao();

        void setValor(double valor);

        void setCPF(std::string cpf);

        std::string getCPF();

        double getValor();

        friend void validarTransacao(Transacao &t, contaBancaria &c);
};

#endif