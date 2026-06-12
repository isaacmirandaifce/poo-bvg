#include <iostream>
#include <string>
#include "usuarioAutenticavel.h"

Usuario::Usuario(){

    std::cout << std::endl << "Criando o usuario" << std::endl;
};

Usuario::~Usuario(){

    std::cout << std::endl << "Apagando o usuario" << std::endl;
};

void Usuario::setID(int novoID) {
    if (novoID >= 1) {
        this->id = novoID;
    };
};

void Usuario::setUsername(std::string novoUser){

    if (!novoUser.empty())
    {
        this->username = novoUser;
        ;
    };
    
};

int Usuario::getID(){ return this->id; };

std::string Usuario::getUsername() { return this -> username; };