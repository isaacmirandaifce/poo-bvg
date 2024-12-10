#include <iostream>
#include "../include/Moto.h"

// Construtor da classe Carro
Moto::Moto(int a, std::string m, std::string mo, std::string c, std::string p) {
    ano = a;
    marca = m;
    modelo = mo;
    cor = c;
    placa = p;
}

// Getter para o modelo
std::string Moto::getModelo() const {
    return modelo;
}

// Getter para o ano
int Moto::getAno() const {
    return ano;
}

//Getter para a marca
std::string Moto::getMarca() const {
    return marca;
}


// Método para mostrar as informações do carro
void Moto::exibirDetalhes() {
    std::cout << "Moto: " << marca << " " << modelo << " (" << ano << ")\n";
    std::cout << "Cor: " << cor << " | Placa: " << placa << "\n" << std::endl;
}
