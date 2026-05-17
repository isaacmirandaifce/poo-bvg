#pragma once
#include <iostream>
#include <string>

class Transacao;

class ContaBancaria{
    private:
    std::string titular;
    std::string cpf;

    protected:
    double saldo;

    public:
    ContaBancaria(std::string nome, std::string documento, double saldoInicial){
        titular = nome;
        cpf = documento;
        saldo = saldoInicial;
    }
    void exibirDados(){
        std::cout << "====Dados basicos da conta====" << std::endl;
        std::cout << "Titular: " <<titular << std::endl;
        std::cout << "CPF: " << cpf << std::endl;
        std::cout << "Saldo atual: R$ "<< saldo <<std::endl;

    }

    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};