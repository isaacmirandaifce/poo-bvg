#include "SensorDiagnostico.h"
#include <iostream>

SensorDiagnostico::SensorDiagnostico(std::string id, int ts, int rpm, double temp) : Dispositivo(id, ts), rpmMotor(rpm), temperaturaFluido(temp) {}

void SensorDiagnostico::processarDados() {
    std::cout << "(Sensor Diagnostico) ID: " << idDispositivo << " ; Motor RPM: " << rpmMotor << ", Temp. Fluido: " << temperaturaFluido << " graus" << std::endl;
}