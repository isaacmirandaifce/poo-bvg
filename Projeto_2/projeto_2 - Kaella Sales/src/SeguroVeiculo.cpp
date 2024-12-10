#include "../include/SeguroVeiculo.h"
#include <iostream>


SeguroVeiculo::SeguroVeiculo(Cliente& cli, float v, std::string vi) 
   : cliente(cli), valor(v), vigencia(vi) {}

void SeguroVeiculo::CalcularValor(){
    valor = 0;
}

std::string SeguroVeiculo::VerificarVigencia(std::string validez){
    if (validez > vigencia){
    return "Inválido";
    }else{
        return "Válido";
    }
}
