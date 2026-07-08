#include "SensorDiagnostico.h"

SensorDiagnostico::SensorDiagnostico(std::string id, int ts, int rpm, double temp)
    : Dispositivo(id, ts), rpmMotor(rpm), temperaturaFluido(temp) {}

SensorDiagnostico::~SensorDiagnostico() {
    std::cout << "[Memoria] Destruindo SensorDiagnostico: " << idDispositivo << "\n";
}

void SensorDiagnostico::processarDados() {
    std::cout << "[OBD-II] Status do Motor -> RPM: " << rpmMotor << " | Temp: " << temperaturaFluido << " C\n";
}
