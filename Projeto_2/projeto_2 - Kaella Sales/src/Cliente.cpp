#include "../include/Cliente.h"
#include <iostream>


Cliente::Cliente(std::string n, std::string cepef){
nome = n;
cpf = cepef;
}

void Cliente::ExibirInformacoes(){
    std::cout << "\n" << std::endl;
    std::cout << "Cliente" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CPF: " << cpf << "\n" << std::endl;
}
