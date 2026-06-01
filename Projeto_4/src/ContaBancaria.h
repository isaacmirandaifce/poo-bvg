#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

// Forward declaration (declaração antecipada) para que o compilador saiba que Transacao existe
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
    
    // Método para exibir dados básicos
    void exibirDados();

    // Declaração da função amiga (friend function)
    friend bool validarTransacao(ContaBancaria& conta, Transacao& transacao);
};

#endif // CONTABANCARIA_H