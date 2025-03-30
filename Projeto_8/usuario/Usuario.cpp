#include "Usuario.h"
#include <iostream>

// Construtor para inicializar as variáveis do usuário
Usuario::Usuario(std::string nome, std::string id) : nome(nome), id(id) {}

// Método para exibir as informações do usuário
void Usuario::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nID: " << id << std::endl;
}
