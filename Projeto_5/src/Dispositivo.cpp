#include "Dispositivo.h"
#include <iostream>

Dispositivo::Dispositivo(std::string id, int ts)
    : idDispositivo(id), timestamp(ts) {}

Dispositivo::~Dispositivo() {
    std::cout << "Dispositivo " << idDispositivo << " destruido." << std::endl;
}