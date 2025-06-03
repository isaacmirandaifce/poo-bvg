#ifndef PESSOA_H
#define PESSOA_H

#include <string> // Para std::string 
#include <iostream> // Para std::cout nos métodos e destrutor

// Declaração da classe Pessoa
class Pessoa {
private: // Atributos privados 
    std::string nome;       // Atributo nome da pessoa 
    std::string telefone;   // Atributo telefone da pessoa 

public: // Métodos públicos 
    Pessoa(); // Construtor padrão 
    Pessoa(std::string nome, std::string telefone); // Construtor parametrizado 
    ~Pessoa(); // Destrutor 

    void imprimirNome();    // Método para imprimir o nome 
    void imprimirTelefone(); // Método para imprimir o telefone 
};

#endif // PESSOA_H