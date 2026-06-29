// Header onde possue a classe contato e seus métodos 


// Header Guards: Elas servem como uma "trava de segurança" 
// que impede que o compilador se confunda 
// ao encontrar a mesma declaração de classe mais de uma vez no mesmo projeto.

#ifndef contato_h // Verifica se a chave "contato_h" existe, caso não
#define contato_h // A chave é criada pelo define

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

// Fim do bloco de proteção
#endif