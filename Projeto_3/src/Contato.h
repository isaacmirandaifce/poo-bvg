#ifndef CONTATO_H
#define CONTATO_H

#include <string>
#include <iostream>

class Contato {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor padrão
    Contato();

    // Construtor parametrizado
    Contato(std::string nome, std::string telefone);

    // Destrutor
    ~Contato();

    // Métodos de exibição
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // CONTATO_H