#include "RastreadorAvancado.h"
#include <iostream>

RastreadorAvancado::RastreadorAvancado(std::string id, int ts, double lat, double lon, int rpm, double temp) : Dispositivo(id, ts), SensorGPS(id, ts, lat, lon), SensorDiagnostico(id, ts, rpm, temp) {}

void RastreadorAvancado::processarDados() {
    std::cout << "--- (Rastreador avançado) Fusão de dados iniciado ---" << std::endl;

    SensorGPS::processarDados();
    SensorDiagnostico::processarDados();

    std::cout << "------------------------------------" << std::endl;
};
