#include "RastreadorAvancado.h"
#include <iostream>

RastreadorAvancado::RastreadorAvancado(std::string id, int time, double lat, double lon, int rpm, double temp)
    : Dispositivo(id, time), SensorGPS(id, time, lat, lon), SensorDiagnostico(id, time, rpm, temp) {}

void RastreadorAvancado::processarDados() {
    std::cout << "[Rastreador Avançado - Fusão IoT] ID: " << idDispositivo 
              << " | Timestamp: " << timestamp << std::endl;
    // Chamada explícita dos métodos das classes bases para compor a unificação
    SensorGPS::processarDados();
    SensorDiagnostico::processarDados();
}