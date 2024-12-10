#include <iostream>
#include "../include/Carro.h"
#include "../include/Cliente.h"
#include "../include/SeguroVeiculo.h"
#include "../include/SeguroMoto.h"
#include "../include/SeguroCarro.h"

int main(){
    // Criar um cliente
    Cliente cliente("Kaella Sales", "123.456.789-00");
    cliente.ExibirInformacoes();
    // Criar uma moto
    Moto minhaMoto(2024, "Yamaha", "R6", "Preta", "XYZ-5678");
    minhaMoto.exibirDetalhes();


    // Criar um carro
    Carro meuCarro(1996, "Toyota", "Corolla LE 1.8", "verde", "ABC-1234");
    meuCarro.setAtualizarCor("Rosa");
    meuCarro.exibirDetalhes();

    // Criar um seguro para a moto
    SeguroMoto seguroBike(minhaMoto, cliente, 1500.0, "12 meses");
    SeguroCarro seguroCar(meuCarro, cliente, 1500.0, "12 meses");
    
    // Calcular o valor do seguro
    seguroBike.CalcularValor();
    seguroCar.CalcularValor();

    // Exibir novamente os detalhes após o cálculo
    seguroBike.exibirDetalhes();
    seguroCar.exibirDetalhes();

    return 0;
}