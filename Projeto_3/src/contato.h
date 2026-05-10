#ifndef contato_h
#define contato_h

#include <iostream>
#include <string>

class Contato {
    private:
        std::string nome;
        std::string telefone;
    
    public:
        Contato(std::string nome, std::string telefone);

        ~Contato();

        void imprimirNome();
        void imprimirTelefone();
};

#endif