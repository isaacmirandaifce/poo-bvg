#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    Pessoa();  // Construtor padrão
    Pessoa(const std::string& nome, const std::string& telefone); // Construtor parametrizado
    ~Pessoa(); // Destrutor

    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // PESSOA_H
