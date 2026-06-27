#include "Usuario.h"

Usuario::Usuario() : nome(""), email(""), tipo(""){}

Usuario::Usuario(std::string n, std::string e, std::string t) :nome(n), email(e), tipo(t) {}