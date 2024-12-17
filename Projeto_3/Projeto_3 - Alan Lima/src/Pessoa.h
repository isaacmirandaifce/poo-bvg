#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor padrão
    Pessoa();

    // Construtor parametrizado
    Pessoa(const std::string& nome, const std::string& telefone);

    // Destrutor
    ~Pessoa();

    // Métodos
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // PESSOA_H
