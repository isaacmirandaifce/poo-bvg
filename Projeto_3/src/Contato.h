#ifndef CONTATO_H
#define CONTATO_H

#include <string>
#include <iostream>

namespace CRM {
    class Contato {
        private:
        std::string nome;
        std::string telefone;

        public:
        Contato(std::string nome, std::string telefone);

        ~Contato();

        void imprimirNome() const;
        void imprimirTelefone() const;
    };
}

#endif 