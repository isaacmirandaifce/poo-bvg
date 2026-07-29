#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <iostream>

// Forward declaration da classe ContaBancaria
class ContaBancaria;

class Transacao {
private:
    double valor;
    std::string data;

public:
    // Construtor
    Transacao(double valor, std::string data);

    // Exibição básica
    void exibirTransacao() const;

    // Declaração da mesma função amiga
    friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

// Protótipo da função amiga independente (não é membro de nenhuma classe)
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);

#endif // TRANSACAO_H