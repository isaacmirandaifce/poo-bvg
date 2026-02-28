#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo(TipoUsuario::ALUNO) {}

Usuario::Usuario(const std::string& nome, const std::string& email, TipoUsuario tipo)
    : nome(nome), email(email), tipo(tipo) {}

    
