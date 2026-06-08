#include "SensorGPS.h"
#include <iostream>

SensorGPS::SensorGPS(std::string idDispositivo, int timestamp, double latitude, double longitude)
    : Dispositivo(idDispositivo, timestamp) {
    this->latitude = latitude;
    this->longitude = longitude;
}

void SensorGPS::processarDados() {
    std::cout << "Sensor GPS [" << idDispositivo << "]" << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "Localizacao: Latitude " << latitude
              << ", Longitude " << longitude << std::endl;
}

void SensorGPS::transmitirPayload() {
    std::cout << "Transmitindo dados GPS em texto puro..." << std::endl;
}

void SensorGPS::transmitirPayload(std::string chaveCripto) {
    std::cout << "Transmitindo dados GPS com criptografia." << std::endl;
    std::cout << "Chave utilizada: " << chaveCripto << std::endl;
}