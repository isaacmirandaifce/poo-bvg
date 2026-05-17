#include <iostream>
#include <string>
#include "contaBancaria.h"

    contaBancaria::contaBancaria(){
        std::cout << "Contato criado." << '\n';
    }

    contaBancaria::~contaBancaria() {
        std::cout << "O titular de nome: " << titular << ". Foi apagado com sucesso." << '\n';
    }

    void contaBancaria::setTitular(std::string nome){
        if (nome != "")
        {
            this->titular = nome;
        }
        else
        {
            std::cout << "erro no nome" << '\n';
        }
        
    };

    void contaBancaria::setCPF(std::string cpf){
        if (cpf != "")
        {
            this->cpf = cpf;
        }
        else
        {
            std::cout << "Erro no cpf" << '\n';
        }
    };

    void contaBancaria::setSaldo(double saldo) {
        if (saldo >= 0)
        {
            this->saldo = saldo;
        }
        else
        {

            std::cout << "Erro de valor" << '\n';
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