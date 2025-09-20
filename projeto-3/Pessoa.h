#ifndef PESSOA_H
#define PESSOA_H

#include <string>   // Necessário para usar o tipo std::string
#include <iostream> // Necessário para usar std::cout no destrutor

class Pessoa {
private:
    // Atributos privados, conforme solicitado
    std::string nome;     // Atributo para o nome da pessoa
    std::string telefone; // Atributo para o telefone da pessoa

public:
    // Métodos públicos [cite: 221]

    // Construtor padrão [cite: 203]
    Pessoa();

    // Construtor parametrizado que inicializa nome e telefone
    Pessoa(std::string nome, std::string telefone);

    // Destrutor que exibe uma mensagem
    ~Pessoa();

    // Métodos para imprimir os dados
    void imprimirNome();     // [cite: 206]
    void imprimirTelefone(); // [cite: 207]
};

#endif // PESSOA_H
