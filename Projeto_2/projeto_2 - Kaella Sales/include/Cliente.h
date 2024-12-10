#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    std::string nome;
    std::string cpf;

public:
    Cliente(std::string n, std::string cpf);
    void ExibirInformacoes();
};

#endif
