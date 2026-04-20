//Código de Alissa Garcia ADS S3

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

using namespace std;

//Declaração da Classe 

class Usuario {
private:

    std::string nome, email, tipo;
// Utilização de atributos privados

public:

     Usuario(); // Construtor Padrão
     Usuario(string nome, string email, string tipo); // Construtor com os parâmetros de entrada nome, email e tipo
// Utilização de métodos públicos

//Método de impressão de dados.
    virtual void gerarRelatorio() = 0; // Método Virtual Puro
    virtual ~Usuario() {}  // destrutor virtual, coloquei porque vi que é uma boa prática de programação
};

#endif // USUARIO_H