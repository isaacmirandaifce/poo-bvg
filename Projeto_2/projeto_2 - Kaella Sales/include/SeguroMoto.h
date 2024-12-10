#ifndef SEGUROMOTO_H
#define SEGUROMOTO_H
#include <string>
#include "SeguroVeiculo.h"
#include "Moto.h"

class SeguroMoto : public SeguroVeiculo {
private:
    Moto& moto; // Referência para um objeto Moto

public:
    SeguroMoto(Moto& moto, Cliente& cli, float v, std::string vi);
    void CalcularValor() override;
    void exibirDetalhes();
};

#endif