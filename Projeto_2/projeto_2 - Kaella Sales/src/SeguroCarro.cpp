#include "../include/SeguroCarro.h"
#include <iostream>

// Construtor
SeguroCarro::SeguroCarro(Carro& carro, Cliente& cli, float v, std::string vi) 
  : c(carro), SeguroVeiculo(cli, v, vi) {}

// Sobrescrevendo o cálculo de valor para SeguroCarro
void SeguroCarro::CalcularValor() {
    valor += 500; // Exemplo de cálculo adicional para carros
}


void SeguroCarro::exibirDetalhes(){
    std::cout << "Seguro" << std::endl;
    std::cout << "Tipo: Automovel" << std::endl;
   std::cout << "Veículo: " << c.getMarca() << " " << c.getModelo() << " " << c.getAno() << std::endl;
    std::cout << "Valor do seguro: " << valor << std::endl;
    std::cout << "Vigência: " << vigencia << "\n" << std::endl;
}