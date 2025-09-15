#include "Usuario.h"

// Construtor padrão
Usuario::Usuario() : nome(""), email(""), tipo("") {}

// Construtor parametrizado
Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& tipo)
    : nome(nome), email(email), tipo(tipo) {}

// Destrutor virtual
Usuario::~Usuario() {}

// Métodos getters
std::string Usuario::getNome() const {
    return nome;
}

std::string Usuario::getEmail() const {
    return email;
}

std::string Usuario::getTipo() const {
    return tipo;
}

// Métodos setters
void Usuario::setNome(const std::string& nome) {
    this->nome = nome;
}

void Usuario::setEmail(const std::string& email) {
    this->email = email;
}

void Usuario::setTipo(const std::string& tipo) {
    this->tipo = tipo;
}

// Método virtual para exibir informações básicas
void Usuario::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
}
