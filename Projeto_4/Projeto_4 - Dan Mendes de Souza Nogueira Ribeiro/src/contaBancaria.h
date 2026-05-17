#ifndef Conta_Bancaria
#define Conta_Bancaria
#include <iostream>
#include <string>

class Transacao;

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
#endif