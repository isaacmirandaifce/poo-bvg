#include "SensorDiagnostico.h"
#include <iostream>
#include <iomanip>

SensorDiagnostico::SensorDiagnostico(const std::string& id, int ts, int rpm, double temp)
    : Dispositivo(id, ts), rpmMotor(rpm), temperaturaFluido(temp) {}

SensorDiagnostico::~SensorDiagnostico() {
    std::cout << "[SensorDiagnostico] Destruindo: " << idDispositivo << "\n";
}

void SensorDiagnostico::processarDados() {
    std::cout << "-------------------------------------------\n";
    std::cout << "[SensorDiagnostico] ID: " << idDispositivo << "\n";
    std::cout << "  RPM do Motor     : " << rpmMotor << " rpm\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "  Temperatura Fluido: " << temperaturaFluido << " °C\n";

    // Avaliação de saúde do motor
    if (rpmMotor > 6000) {
        std::cout << "  ALERTA: RPM crítico! Risco de dano ao motor.\n";
    } else if (temperaturaFluido > 100.0) {
        std::cout << "  ALERTA: Temperatura do fluido elevada!\n";
    } else {
        std::cout << "  Motor operando dentro dos parâmetros normais.\n";
    }
    std::cout << "-------------------------------------------\n";
}

int    SensorDiagnostico::getRpm()  const{return rpmMotor;}
double SensorDiagnostico::getTemp() const{return temperaturaFluido;}