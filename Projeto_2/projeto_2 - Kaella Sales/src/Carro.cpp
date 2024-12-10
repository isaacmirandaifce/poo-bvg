#include "../include/Carro.h"
#include <iostream>

// Construtor da classe Carro
Carro::Carro(int a, std::string m, std::string mo, std::string c, std::string p) {
    ano = a;
    marca = m;
    modelo = mo;
    cor = c;
    placa = p;
}

// Getter para o modelo
std::string Carro::getModelo() const {
    return modelo;
}

// Getter para o ano
int Carro::getAno() const {
    return ano;
}

//Getter para a marca
std::string Carro::getMarca() const {
    return marca;
}


// Método para mostrar as informações do carro
void Carro::exibirDetalhes() {
    std::cout << "Carro: " << marca << " " << modelo << " (" << ano << ")\n";
    std::cout << "Cor: " << cor << " | Placa: " << placa << "\n" << std::endl;
}


void Carro::setAtualizarCor(std::string novaCor) {
    cor = novaCor;
}

