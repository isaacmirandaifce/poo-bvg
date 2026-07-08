#include "Dispositivo.h"

// Implementação do Construtor
Dispositivo::Dispositivo(std::string id, int ts) 
    : idDispositivo(id), timestamp(ts) {}

// Implementação do Destrutor Virtual
Dispositivo::~Dispositivo() {
    std::cout << "[Sistema] Destruindo base do dispositivo: " << idDispositivo << "\n";
}
