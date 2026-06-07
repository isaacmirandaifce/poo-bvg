#include "SensorGPS.h"
#include <iostream>

SensorGPS::SensorGPS(std::string id, int ts, double lat, double lon)
    : Dispositivo(id, ts), latitude(lat), longitude(lon) {}

void SensorGPS::processarDados() {
    std::cout << "[GPS] Dispositivo: " << idDispositivo
              << " | Timestamp: " << timestamp
              << " | Latitude: " << latitude
              << " | Longitude: " << longitude << std::endl;
}

void SensorGPS::transmitirPayload() {
    std::cout << "[GPS] Transmitindo em texto puro -> Lat: "
              << latitude << " Lon: " << longitude << std::endl;
}

void SensorGPS::transmitirPayload(std::string chaveCripto) {
    std::cout << "[GPS] Transmitindo com criptografia [" << chaveCripto
              << "] -> Lat: " << latitude << " Lon: " << longitude << std::endl;
}