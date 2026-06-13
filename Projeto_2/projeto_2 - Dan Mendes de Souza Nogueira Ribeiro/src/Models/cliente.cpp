#include <iostream>
#include <string>
#include "cliente.h"


    void cliente::setNome(std::string nomeAdicionar) { nome = nomeAdicionar; };

    void cliente::setCPF(std::string cpfAdicionar) { cpf = cpfAdicionar; };

    std::string cliente::getCPF() { return cpf; };

    std::string cliente::getNome() { return nome; };
