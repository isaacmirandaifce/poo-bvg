#include "SensorGPS.h"
#include <iostream>

SensorGPS::SensorGPS(std::string id, int ts, double lat, double lon) : Dispositivo(id, ts), latitude(lat), longitude(lon) {}

void SensorGPS::processarDados() {
    std::cout << "(Sensor GPS) ID: " << idDispositivo << " ; Latitude: " << latitude << ", Lon: " << longitude << std::endl;
}

void SensorGPS::transmitirPayload() {
    std::cout << ">> Transmitindo dados abertos em texto puro..." << std::endl;
}

void SensorGPS:: transmitirPayload(std::string chaveCripto) {
    std::cout << ">> Transmitindo dados criptografados usando a chave: " << chaveCripto << std::endl;
}