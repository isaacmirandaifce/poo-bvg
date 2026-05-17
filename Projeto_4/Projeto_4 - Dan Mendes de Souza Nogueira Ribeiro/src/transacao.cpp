#include <iostream>
#include <string>
#include "transacao.h"
#include "contaBancaria.h"

Transacao::Transacao()
{
    std::cout << '\n' << "Pedido de transação criado." << '\n';
}

Transacao::~Transacao()
{
    std::cout << '\n' << "O pedido de transação feito pelo cpf: " << cpf << ". Foi encerrado." << '\n';
}

void Transacao::setCPF(std::string cpf)
{
    if (cpf != "")
    {
        this->cpf = cpf;
    }
    else
    {
        std::cout << '\n' << "Erro no cpf" << '\n';
    }
    
};

void Transacao::setValor(double valor)
{
    if (valor > 0)
    {
        this->valor = valor;
    } else {

        std::cout << '\n' << "Erro de valor" << '\n';
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

// Implementação da Função Amiga
void validarTransacao(Transacao &t, contaBancaria &c) {

    double valor = t.getValor();

    if (valor > c.saldo)
    {
        std::cout << '\n' << "impossivel realizar a transação" << '\n';
    }
    else
    {
        c.saldo = c.saldo - valor;
    }
    
};