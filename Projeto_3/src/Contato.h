#ifndef CONTATO_H
#define CONTATO_H


#include <string>
#include <iostream>

class Contato {
    private:
        std::string nome;
        std::string telefone;
    

    public:
        Contato(std::string nome, std::string telefone);

        //destrutor
        ~Contato();

        void imprimirNome() const;
        void imprimirTelefone() const;
};

#endif 