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
        this->titular = nome;
    };

    void contaBancaria::setCPF(std::string cpf){
        this->cpf = cpf;
    };

    void contaBancaria::setSaldo(double saldo) {
        this->saldo = saldo;
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