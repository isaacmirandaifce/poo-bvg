#include "RastreadorAvancado.h"
#include <iostream>

RastreadorAvancado::RastreadorAvancado(std::string id, int ts,
                                       double lat, double lon,
                                       int rpm, double temp)
    : SensorGPS(id, ts, lat, lon),
      SensorDiagnostico(id, ts, rpm, temp) {}

void RastreadorAvancado::processarDados() {
    std::cout << "[RASTREADOR AVANCADO] Dispositivo: " << SensorGPS::idDispositivo
              << " | Timestamp: " << SensorGPS::timestamp << std::endl;
    std::cout << "  >> ";
    SensorGPS::processarDados();
    std::cout << "  >> ";
    SensorDiagnostico::processarDados();
}