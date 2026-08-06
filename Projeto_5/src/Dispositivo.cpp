#include "Dispositivo.h"
#include <iostream>

Dispositivo::Dispositivo(const std::string& id, int ts)
    : idDispositivo(id), timestamp(ts) {}

Dispositivo::~Dispositivo() {
    std::cout << "[Dispositivo] Liberando recursos do dispositivo ID: "
              << idDispositivo << std::endl;
}

std::string Dispositivo::getId() const {
    return idDispositivo;
}

int Dispositivo::getTimestamp() const {
    return timestamp;
}
