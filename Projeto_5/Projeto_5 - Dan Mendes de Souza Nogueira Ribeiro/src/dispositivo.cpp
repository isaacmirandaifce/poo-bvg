#include <iostream>
#include <string>
#include "dispositivo.h"

Dispositivo::Dispositivo(){
    std::cout << std::endl << "criação do dispositivo" << std::endl;
};

Dispositivo::~Dispositivo(){
    std::cout << std::endl << "remoção do dispositivo" << std::endl;
};
