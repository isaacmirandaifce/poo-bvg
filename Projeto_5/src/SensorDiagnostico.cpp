#include "SensorDiagnostico.h"
#include <iostream>

SensorDiagnostico::SensorDiagnostico(std::string id, int time, int rpm, double temp)
    : Dispositivo(id, time), rpmMotor(rpm), temperaturaFluido(temp) {}

void SensorDiagnostico::processarDados() {
    std::cout << "[OBD-II] ID: " << idDispositivo 
              << " | Timestamp: " << timestamp 
              << " | RPM: " << rpmMotor 
              << " | Temp. Fluido: " << temperaturaFluido << "°C" << std::endl;
}