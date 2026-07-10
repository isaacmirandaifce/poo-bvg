#include "SensorGPS.h"
#include <iostream>
#include <iomanip>
 
SensorGPS::SensorGPS(const std::string& id, int ts, double lat, double lon)
    : Dispositivo(id, ts), latitude(lat), longitude(lon) {}
 
SensorGPS::~SensorGPS() {
    std::cout << "[SensorGPS] Destruindo: " << idDispositivo << "\n";
}
 
void SensorGPS::processarDados() {
    std::cout << "-------------------------------------------\n";
    std::cout << "[SensorGPS] ID: " << idDispositivo << "\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "  Latitude : " << latitude  << "\n";
    std::cout << "  Longitude: " << longitude << "\n";
    std::cout << "  Timestamp: " << timestamp << "\n";
    std::cout << "-------------------------------------------\n";
}
 
// Sobrecarga 1: transmissão aberta em texto puro
void SensorGPS::transmitirPayload() {
    std::cout << "[SensorGPS] Transmitindo payload ABERTO:\n";
    std::cout << "  { id: " << idDispositivo
              << ", lat: " << latitude
              << ", lon: " << longitude << " }\n";
}
 
// Sobrecarga 2: transmissão segura com chave de criptografia
void SensorGPS::transmitirPayload(std::string chaveCripto) {
    std::cout << "[SensorGPS] Transmitindo payload SEGURO (chave: "
              << chaveCripto << "):\n";
    // Simula uma assinatura simples concatenando a chave
    std::string payload = "ID=" + idDispositivo
                        + "&LAT=" + std::to_string(latitude)
                        + "&LON=" + std::to_string(longitude);
    std::cout << " Payload assinado: [ENC::" << chaveCripto
              << "::" << payload << "]\n";
}
 
double SensorGPS::getLatitude()  const{return latitude;}
double SensorGPS::getLongitude() const{return longitude;}
 
