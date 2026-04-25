//Código de Alissa Garcia ADS S3

//Declaração da Classe 


#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;
// Utilize `namespace std` para simplificar a escrita do código


class Pessoa {
private:

    std::string nome, telefone;
// Utilização de atributos privados

public:

     Pessoa(); // Construtor Padrão
     Pessoa(string nome, string telefone); // Construtor com os parâmetros de entrada nome e telefone
    ~Pessoa(); // Destrutor
// Utilização de métodos públicos

//Métodos de impressão de dados.
    void imprimirNome(); 
    void imprimirTelefone();
};

#endif // PESSOA_H
