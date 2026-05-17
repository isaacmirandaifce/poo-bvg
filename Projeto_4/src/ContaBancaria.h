// Header Guards
#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

// Forward Declaration...
class Transacao;

class ContaBancaria {
// Atributos privados dessa classe
    private:
        std::string titular;
        std::string cpf;
// Atributo protegido, podendo ser acessado apenas por classes que herdam de ContaBancaria
    protected:
        double saldo;

    public:
        ContaBancaria(std::string t, std::string c, double s);
        void exibirDados() const;

// Função amiga responsável por permitir que a classe ContaBancaria tenha acesso a seus atributos
        friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif