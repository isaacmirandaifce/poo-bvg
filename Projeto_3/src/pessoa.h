#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;    // Nome da pessoa
    std::string telefone; // Telefone da pessoa

public:
    Pessoa();  // Construtor padrão
    Pessoa(const std::string& nome, const std::string& telefone);  // Construtor com parâmetros

    ~Pessoa();  // Destrutor

    void imprimirNome() const;  // Método para imprimir o nome
    void imprimirTelefone() const;  // Método para imprimir o telefone
};

#endif // PESSOA_H
