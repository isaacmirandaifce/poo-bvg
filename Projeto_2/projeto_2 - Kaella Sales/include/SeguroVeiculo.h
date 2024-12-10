#ifndef SEGURO_H
#define SEGURO_H

#include <string>
#include "Cliente.h"

class SeguroVeiculo {
protected:
    Cliente& cliente;
    float valor;
    std::string vigencia;

public:
    SeguroVeiculo(Cliente& cli, float v, std::string vi);
    virtual void CalcularValor();
    std::string VerificarVigencia(std::string validez);
};

#endif
