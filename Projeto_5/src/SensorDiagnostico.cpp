#include "SensorDiagnostico.h"
#include <iostream>

SensorDiagnostico::SensorDiagnostico(std::string id, int ts, int rpm, double temp) 
    : Dispositivo(id, ts), rpmMotor(rpm), temperaturaFluido(temp) {}

void SensorDiagnostico::processarDados() {
    std::cout << "[DIAGNÓSTICO] ID: " << idDispositivo << " | Tempo: " << timestamp 
              << " | Motor: " << rpmMotor << " RPM | Temp: " << temperaturaFluido << "°C" << std::endl;
}