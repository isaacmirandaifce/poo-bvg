#include "SensorDiagnostico.h"
#include <iostream>

namespace {
    // Limiares simples de alerta usados para avaliar a saude do motor.
    constexpr int RPM_LIMITE = 6000;
    constexpr double TEMP_LIMITE = 110.0;
}

SensorDiagnostico::SensorDiagnostico(const std::string& id, int ts, int rpm, double temp)
    : Dispositivo(id, ts), rpmMotor(rpm), temperaturaFluido(temp) {}

SensorDiagnostico::~SensorDiagnostico() {
    std::cout << "[SensorDiagnostico] Encerrando sensor de diagnostico ID: "
              << idDispositivo << std::endl;
}

void SensorDiagnostico::processarDados() {
    const bool alerta = (rpmMotor > RPM_LIMITE) || (temperaturaFluido > TEMP_LIMITE);
    std::cout << "[OBD-II] Dispositivo " << idDispositivo
              << " | Timestamp: " << timestamp
              << " | RPM: " << rpmMotor
              << " | Temp. Fluido: " << temperaturaFluido << "C"
              << " | Status: " << (alerta ? "ALERTA" : "NORMAL")
              << std::endl;
}

int SensorDiagnostico::getRpmMotor() const { return rpmMotor; }
double SensorDiagnostico::getTemperaturaFluido() const { return temperaturaFluido; }
