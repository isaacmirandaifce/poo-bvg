#include <iostream>
#include <string>
#include "transacao.h"

void Transacao::setCPF(std::string cpf)
{
    if (cpf != "")
    {
        this->cpf = cpf;
    }
    else
    {
        std::cout << "Erro no cpf" << '\n';
    }
    
};

void Transacao::setValor(double valor)
{
    if (valor > 0)
    {
        this->valor = valor;
    } else {

        std::cout << "Erro de valor" << '\n';
    }
};

std::string Transacao::getCPF()
{
    return this->cpf;
};

double Transacao::getValor()
{
    return this->valor;
};