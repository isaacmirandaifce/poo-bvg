#include "Usuario.h"

#include <stdexcept>

Usuario::Usuario() : nome(""), email(""), tipo("") {}

Usuario::Usuario(std::string nome, std::string email, std::string tipo)
{
    if (nome.empty())
    {
        throw std::invalid_argument("Erro: O nome do usuário não pode ser vazio.");
    }

    this->nome = nome;
    this->email = email;
    this->tipo = tipo;
}
