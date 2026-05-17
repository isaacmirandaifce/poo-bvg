#include <iostream>
#include <string>
#include "transacao.h"
#include "contaBancaria.h"

Transacao::Transacao()
{
    std::cout << "Pedido transação criado." << '\n';
}

Transacao::~Transacao()
{
    std::cout << "O pedido de transação feito pelo cpf: " << titular << ". Foi encerrado." << '\n';
}

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

void validarTransacao(Transacao &t, contaBancaria &c) {

    double valor = t.getValor();

    if (valor > c.saldo)
    {
        std::cout << "impossivel realizar a transação" << '\n';
    }
    else
    {
        c.saldo = c.saldo - valor;
    }
    
};