#include <iostream>
#include <string>
#include "contaBancaria.h"

    contaBancaria::contaBancaria(){
        std::cout << '\n' << "Conta criado." << '\n';
    }

    contaBancaria::~contaBancaria() {
        std::cout << '\n' << "O titular da conta de nome: " << titular << ". Foi apagado com sucesso." << '\n';
    }

    void contaBancaria::setTitular(std::string nome){
        if (nome != "")
        {
            this->titular = nome;
        }
        else
        {
            std::cout << '\n' << "erro no nome" << '\n';
        }
        
    };

    void contaBancaria::setCPF(std::string cpf){
        if (cpf != "")
        {
            this->cpf = cpf;
        }
        else
        {
            std::cout << '\n' << "Erro no cpf" << '\n';
        }
    };

    void contaBancaria::setSaldo(double saldo) {
        if (saldo >= 0)
        {
            this->saldo = saldo;
        }
        else
        {

            std::cout << '\n' << "Erro de valor" << '\n';
        }
    };

    std::string contaBancaria::getTitular(){
        return this->titular;
    };

    std::string contaBancaria::getCPF(){
        return this->cpf;
    };

    double contaBancaria::getSaldo(){
        return this->saldo;
    };