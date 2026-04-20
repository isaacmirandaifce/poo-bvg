#include "Usuario.h"

Usuario::Usuario() {
    nome = "NULL";
    email = "NULL";
    tipo = TipoUsuario::ALUNO;
}

Usuario::Usuario(string nome, string email, TipoUsuario tipo) {
    this->nome = nome;
    this->email = email;
    this->tipo = tipo;
}
