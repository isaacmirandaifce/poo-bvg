#pragma once
#include <string>

class Contato {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor parametrizado
    Contato(std::string nome, std::string telefone);

    // Destrutor
    ~Contato();

    // Métodos de impressão
    void imprimirNome();
    void imprimirTelefone();
};
