#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nome, const std::string& email, int id, TipoUsuario tipo)
    : nome(nome), email(email), id(id), tipo(tipo) {}

std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
int Usuario::getId() const { return id; }
TipoUsuario Usuario::getTipo() const { return tipo; }

void Usuario::setNome(const std::string& nome) { this->nome = nome; }
void Usuario::setEmail(const std::string& email) { this->email = email; }

void Usuario::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nID: " << id << std::endl;
}
