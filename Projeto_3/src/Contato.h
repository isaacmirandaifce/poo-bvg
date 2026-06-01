#ifndef CONTATO_H
#define CONTATO_H

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

#endif // CONTATO_H