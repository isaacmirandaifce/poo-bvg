#ifndef SEGUROCARRO_H
#define SEGUROCARRO_H

#include <string>
#include "Carro.h"
#include "SeguroVeiculo.h"

class SeguroCarro: public SeguroVeiculo {
private:
    Carro& c;

public:
SeguroCarro(Carro& carro, Cliente& cli, float v, std::string vi);
void CalcularValor() override;
void exibirDetalhes();
};

#endif