#pragma once
#include <string>

// Declaração antecipada da classe Transacao para a friend function
class Transacao;

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo;

public:
    ContaBancaria(std::string titular, std::string cpf, double saldo);
    
    // Função amiga que terá acesso aos membros protegidos/privados
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};
