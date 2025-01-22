#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>
#include <iostream>

class Pessoa{
private:
std::string nome;
std::string telefone;

public:
    //construtor
    Pessoa(std::string nome, std::string fone);

    //destrutor
    ~Pessoa();
    
    // Métodos para acessar os atributos
    std::string getNome() const;
    std::string getTelefone() const;

    //métodos para imprimir informações
    void ImprimirNome();
    void ImprimirTelefone();
    void exibirInformacoes() const;
};
#endif
//nesse arquivo declaramos todos os metodos e atributos relacionados a classe(como se fosse uma prototipação)