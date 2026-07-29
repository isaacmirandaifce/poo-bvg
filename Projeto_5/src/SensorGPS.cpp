#include "SensorGPS.h"
#include <iostream>

SensorGPS::SensorGPS(std::string id, int time, double lat, double lon)
    : Dispositivo(id, time), latitude(lat), longitude(lon) {}

void SensorGPS::processarDados() {
    std::cout << "[GPS] ID: " << idDispositivo 
              << " | Timestamp: " << timestamp 
              << " | Lat: " << latitude 
              << ", Lon: " << longitude << std::endl;
}

void SensorGPS::transmitirPayload() {
    std::cout << "[GPS - Aberto] Transmitindo coordenadas em texto puro para o servidor..." << std::endl;
}

void SensorGPS::transmitirPayload(std::string chaveCripto) {
    std::cout << "[GPS - Criptografado] Assinatura/Chave aplicada (" << chaveCripto << "). Transmissão segura concluída." << std::endl;
}