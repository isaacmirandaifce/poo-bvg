#include <iostream>
#include <string>
#include "transacao.h"

void Transacao::setID(int id)
{
    if (id>0)
    {
        this->id = id;
    } else
    {
        std::cout << std::endl << "erro no ID" << std::endl;
    }
};
void Transacao::setValor(double valor){
    if (valor >= 0)
    {
        this->valor = valor;
    }
    else
    {
        std::cout << std::endl << "erro no valor" << std::endl;
    }
};
void Transacao::setTipo(std::string tipo){
    if (tipo != "")
    {
        this->tipo = tipo;
    }
    else
    {
        std::cout << std::endl
                  << "erro no tipo" << std::endl;
    }
};

int Transacao::getID() const{ return this->id; };
double Transacao::getValor() const { return this->valor; };
std::string Transacao::getTipo() const { return this->tipo; };