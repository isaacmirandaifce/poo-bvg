#include "SensorGPS.h"
#include <iostream>

SensorGPS::SensorGPS(std::string id, int ts, double lat, double lon) 
    : Dispositivo(id, ts), latitude(lat), longitude(lon) {}

void SensorGPS::processarDados() {
    std::cout << "[GPS] ID: " << idDispositivo << " | Tempo: " << timestamp 
              << " | Coordenadas: (" << latitude << ", " << longitude << ")" << std::endl;
}

void SensorGPS::transmitirPayload() {
    std::cout << " -> Transmitindo payload GPS (Texto Puro)..." << std::endl;
}

void SensorGPS::transmitirPayload(std::string chaveCripto) {
    std::cout << " -> Transmitindo payload GPS (Criptografado com chave: " << chaveCripto << ")" << std::endl;
}