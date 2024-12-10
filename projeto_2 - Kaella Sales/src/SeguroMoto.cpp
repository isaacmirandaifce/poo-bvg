#include "../include/SeguroMoto.h"
#include <iostream>

SeguroMoto::SeguroMoto(Moto& moto, Cliente& cli, float v, std::string vi)
    : moto(moto), SeguroVeiculo(cli, v, vi) {}

void SeguroMoto::exibirDetalhes() {
    std::cout << "Seguro" << std::endl;
    std::cout << "Tipo: Motocicleta" << std::endl;
    std::cout << "Veículo: " << moto.getMarca() << " " << moto.getModelo() << " " << moto.getAno() << std::endl;
    std::cout << "Valor do seguro: " << valor << std::endl;
    std::cout << "Vigência: " << vigencia << "\n" << std::endl;
}

void SeguroMoto::CalcularValor(){
    valor += 275.0;
}
