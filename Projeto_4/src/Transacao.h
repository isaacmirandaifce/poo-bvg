// Header Guards
#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

// Forward Declaration...
class ContaBancaria;

class Transacao {
    private:
        double valor;
        std::string data;
    
        public:
            Transacao(double v, std::string d);

            // Função amiga responsável por permitir que a classe Transacao tenha acesso a seus atributos
            friend bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);
};

#endif