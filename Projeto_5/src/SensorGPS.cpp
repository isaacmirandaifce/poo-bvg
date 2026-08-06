#include "SensorGPS.h"
#include <iostream>
#include <iomanip>

SensorGPS::SensorGPS(const std::string& id, int ts, double lat, double lon)
    : Dispositivo(id, ts), latitude(lat), longitude(lon) {}

SensorGPS::~SensorGPS() {
    std::cout << "[SensorGPS] Encerrando sensor GPS ID: " << idDispositivo << std::endl;
}

void SensorGPS::processarDados() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "[GPS] Dispositivo " << idDispositivo
              << " | Timestamp: " << timestamp
              << " | Coordenadas: (" << latitude << ", " << longitude << ")"
              << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void SensorGPS::transmitirPayload() {
    std::cout << "  [TX] Payload em texto puro -> lat=" << latitude
              << ", lon=" << longitude << std::endl;
}

void SensorGPS::transmitirPayload(const std::string& chaveCripto) {
    std::cout << "  [TX] Payload SEGURO (assinado com chave \"" << chaveCripto
              << "\") -> lat=" << latitude << ", lon=" << longitude << std::endl;
}

double SensorGPS::getLatitude() const { return latitude; }
double SensorGPS::getLongitude() const { return longitude; }
