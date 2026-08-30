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

    // Métodos
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif // CONTATO_H