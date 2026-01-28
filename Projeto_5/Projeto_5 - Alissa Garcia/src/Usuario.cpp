//Código de Alissa Garcia ADS S3

#include "Usuario.h"

//Implementação da Classe

// Construtor padrão
    Usuario::Usuario(){
        this->nome  = "NULL";
        this->email = "NULL";
        this->tipo  = "NULL";

        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Usuario::Usuario(string nome, string email, string tipo){
        this->nome  = nome;
        this->email = email;
        this->tipo  = tipo;
    }


// Metodo de impressao das informações:
    void Usuario::gerarRelatorio(){
        std::cout << "O nome do Usuário é: " << this->nome << endl;
        std::cout << "O e-mail é: " << this->email << endl;
        std::cout << "O tipo é: " << this->tipo << endl << endl;
        
    }
