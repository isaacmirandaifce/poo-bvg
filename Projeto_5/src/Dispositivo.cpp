#include "Dispositivo.h"
#include <iostream>
 
Dispositivo::Dispositivo(const std::string& id, int ts)
    : idDispositivo(id), timestamp(ts) {}
 
Dispositivo::~Dispositivo() {
    std::cout << "[Dispositivo] Destruindo: " << idDispositivo << "\n";
}
 
std::string Dispositivo::getId() const {
    return idDispositivo;
}