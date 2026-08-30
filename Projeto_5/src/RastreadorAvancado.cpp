#include "RastreadorAvancado.h"
#include <iostream>

RastreadorAvancado::RastreadorAvancado(std::string id, int ts, double lat, double lon, int rpm, double temp)
    : Dispositivo(id, ts), // Inicialização explícita da base virtual
      SensorGPS(id, ts, lat, lon), 
      SensorDiagnostico(id, ts, rpm, temp) {}

void RastreadorAvancado::processarDados() {
    std::cout << "[RASTREADOR AVANÇADO] ID: " << idDispositivo << " | Tempo: " << timestamp << std::endl;
    std::cout << "  - Sub-módulo GPS ativado..." << std::endl;
    SensorGPS::processarDados(); // Reaproveita o método pai para evitar código duplicado
    std::cout << "  - Sub-módulo Diagnóstico ativado..." << std::endl;
    SensorDiagnostico::processarDados();
}