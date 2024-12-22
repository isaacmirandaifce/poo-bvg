#ifndef PESSOA_H
#define PESSOA_H

#include <string>   // Necessário para std::string
#include <iostream> // Necessário para std::cout e std::endl

class Pessoa {
private:
    std::string nome;       // Nome da pessoa
    std::string telefone;   // Telefone da pessoa

public:
    // Construtor padrão
    Pessoa();

    // Construtor parametrizado
    Pessoa(const std::string& nome, const std::string& telefone);

    // Destrutor
    ~Pessoa();

    // Métodos para imprimir os dados
    void imprimirNome() const;
    void imprimirTelefone() const;

    // Métodos de acesso (getters)
    const std::string& getNome() const;
    const std::string& getTelefone() const;
};

#endif // PESSOA_H
