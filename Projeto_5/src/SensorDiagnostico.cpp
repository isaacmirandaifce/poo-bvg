#include "SensorDiagnostico.h"
#include <iostream>

SensorDiagnostico::SensorDiagnostico(std::string idDispositivo, int timestamp, int rpmMotor, double temperaturaFluido)
    : Dispositivo(idDispositivo, timestamp) {
    this->rpmMotor = rpmMotor;
    this->temperaturaFluido = temperaturaFluido;
}

void SensorDiagnostico::processarDados() {
    std::cout << "Sensor Diagnostico [" << idDispositivo << "]" << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "RPM do motor: " << rpmMotor << std::endl;
    std::cout << "Temperatura do fluido: " << temperaturaFluido << " C" << std::endl;

    if (temperaturaFluido > 100) {
        std::cout << "Alerta: temperatura elevada no motor!" << std::endl;
    } else {
        std::cout << "Status do motor: normal." << std::endl;
    }
}