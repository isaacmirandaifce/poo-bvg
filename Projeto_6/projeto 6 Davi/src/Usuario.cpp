
#include "../include/Usuario.h"

Usuario::Usuario(std::string nome, std::string login) : nome(nome), login(login) {}

std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getLogin() const {
    return login;
}
