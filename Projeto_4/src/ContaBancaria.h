#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

// Forward declaration da classe Transacao para a assinatura da função amiga
class Transacao; 

class ContaBancaria {
private:
    std::string titular;
    std::string cpf;

protected:
    double saldo;

public:
    // Construtor
    ContaBancaria(std::string titular, std::string cpf, double saldo);
    
    // Método pra exibir dados básicos
    void exibirDados() const;

    // Declaração da função amiga em C++
   friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif