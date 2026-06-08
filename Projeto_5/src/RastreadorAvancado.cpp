#include "RastreadorAvancado.h"
#include <iostream>

RastreadorAvancado::RastreadorAvancado(
    std::string idDispositivo,
    int timestamp,
    double latitude,
    double longitude,
    int rpmMotor,
    double temperaturaFluido
)
    : SensorGPS(idDispositivo, timestamp, latitude, longitude),
      SensorDiagnostico(idDispositivo, timestamp, rpmMotor, temperaturaFluido) {
}

void RastreadorAvancado::processarDados() {
    std::cout << "Rastreador Avancado processando dados combinados..." << std::endl;

    SensorGPS::processarDados();

    std::cout << "-----------------------------" << std::endl;

    SensorDiagnostico::processarDados();
}