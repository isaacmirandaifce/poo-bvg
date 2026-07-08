#include "SensorGPS.h"

SensorGPS::SensorGPS(std::string id, int ts, double lat, double lon)
    : Dispositivo(id, ts), latitude(lat), longitude(lon) {}

SensorGPS::~SensorGPS() {
    std::cout << "[Memoria] Destruindo SensorGPS: " << idDispositivo << "\n";
}

void SensorGPS::processarDados() {
    std::cout << "[GPS] Coordenadas -> Lat: " << latitude << " | Lon: " << longitude << "\n";
}

void SensorGPS::transmitirPayload() {
    std::cout << "[GPS] Transmitindo dados abertos em texto puro...\n";
}

void SensorGPS::transmitirPayload(std::string chaveCripto) {
    std::cout << "[GPS] Transmitindo dados seguros. Chave cripto: " << chaveCripto << "\n";
}
