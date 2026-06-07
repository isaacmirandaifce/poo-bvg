#include "Dispositivo.h"

Dispositivo::Dispositivo(std::string id, int tempo) {
    idDispositivo = id;
    timestamp = tempo;
}

Dispositivo::~Dispositivo() {
}