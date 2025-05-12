#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

class Cliente {
public:
    std::string nome;
    int idade;
    double saldo;    

    Cliente(const std::string& nome, int idade, double saldo)
        : nome(nome), idade(idade), saldo(saldo) {}


    
    void mostrarInformacoes() const {
        std::cout << "Cliente: " << nome << ", Idade: " << idade << ", Saldo: " << saldo << std::endl;
    }

    
    void atualizarSaldo(double valor) {
        saldo += valor;
    }
};

#endif