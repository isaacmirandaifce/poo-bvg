#include "SensorGPS.h"

SensorGPS::SensorGPS(std::string id, int tempo,
                     double lat, double lon)
    : Dispositivo(id, tempo)
{
    latitude = lat;
    longitude = lon;
}

void SensorGPS::processarDados() {

    // Exibe as coordenadas recebidas pelo GPS
    std::cout << "\n=== SENSOR GPS ===" << std::endl;
    std::cout << "ID: " << idDispositivo << std::endl;
    std::cout << "Latitude: " << latitude << std::endl;
    std::cout << "Longitude: " << longitude << std::endl;
}

void SensorGPS::transmitirPayload() {

    // Envio simples sem criptografia
    std::cout << "Transmitindo dados em texto puro..."
              << std::endl;
}

void SensorGPS::transmitirPayload(std::string chaveCripto) {

    // Sobrecarga do método para simular envio seguro
    std::cout << "Transmitindo dados criptografados com chave: "
              << chaveCripto << std::endl;
}