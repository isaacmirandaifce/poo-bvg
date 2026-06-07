#include <iostream>
#include <string>
#include "dispositivo.h"

Dispositivo::Dispositivo(){
    std::cout << std::endl << "Criação do dispositivo" << std::endl;
};

Dispositivo::~Dispositivo(){
    std::cout << std::endl << "Remoção do dispositivo" << std::endl;
};
