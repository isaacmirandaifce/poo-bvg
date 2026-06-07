#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

class Transacao {
public:
    int id;
    double valor;
    std::string tipo;

    Transacao(int id, double valor, std::string tipo);
    void exibir() const;
};

#endif