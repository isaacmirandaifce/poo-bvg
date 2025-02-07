#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(const string& nome, const string& email, const string& tipo)
    : nome(nome), email(email), tipo(tipo) {}
