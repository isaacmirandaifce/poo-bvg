#include "../headers/Usuario.h"

Usuario::Usuario(const std::string& nome, const std::string& email, 
                 const std::string& matricula, TipoUsuario tipo)
    : nome(nome), email(email), matricula(matricula), tipo(tipo) {}

std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
std::string Usuario::getMatricula() const { return matricula; }
TipoUsuario Usuario::getTipo() const { return tipo; }

void Usuario::setNome(const std::string& nome) { this->nome = nome; }
void Usuario::setEmail(const std::string& email) { this->email = email; }
void Usuario::setMatricula(const std::string& matricula) { this->matricula = matricula; }