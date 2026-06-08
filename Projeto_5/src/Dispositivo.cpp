#include "Dispositivo.h"

Dispositivo::Dispositivo(std::string idDispositivo, int timestamp) {
    this->idDispositivo = idDispositivo;
    this->timestamp = timestamp;
}

Dispositivo::~Dispositivo() {
}

std::string Dispositivo::getIdDispositivo() const {
    return idDispositivo;
}

int Dispositivo::getTimestamp() const {
    return timestamp;
}