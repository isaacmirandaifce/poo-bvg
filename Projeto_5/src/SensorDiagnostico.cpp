#include "SensorDiagnostico.h"
#include <iostream>

SensorDiagnostico::SensorDiagnostico(std::string id, int ts, int rpm, double temp)
    : Dispositivo(id, ts), rpmMotor(rpm), temperaturaFluido(temp) {}

void SensorDiagnostico::processarDados() {
    std::cout << "[DIAGNOSTICO] Dispositivo: " << idDispositivo
              << " | Timestamp: " << timestamp
              << " | RPM: " << rpmMotor;

    if (rpmMotor > 6000)
        std::cout << " (ALERTA: RPM critico!)";

    std::cout << " | Temperatura: " << temperaturaFluido << "°C";

    if (temperaturaFluido > 100.0)
        std::cout << " (ALERTA: Superaquecimento!)";

    std::cout << std::endl;
}