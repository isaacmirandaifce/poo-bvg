#include <iostream>
#include <string>
#include "sensorDiagnostico.h"

void SensorDiagnostico::setRPMMotor(int newRPM){this->rpmMotor = newRPM;};
void SensorDiagnostico::setTemperaturaFluido(double newTemflu) { this->temperaturaFluido = newTemflu;};

int SensorDiagnostico::getRPMMotor() { return this->rpmMotor;};
double SensorDiagnostico::gettemperaturaFluido() { return this->temperaturaFluido;};

void SensorDiagnostico::processarDados() {

    int rpmMotor = this -> rpmMotor;
    double temperaturaFluido = this->temperaturaFluido;

    if (rpmMotor >= 6000 || temperaturaFluido > 105)
    {
        std::cout << std::endl << "Sistema em estado critico, risco de fusão";
    }
    else if (temperaturaFluido > 90 && temperaturaFluido < 105)
    {
        std::cout << std::endl << "Sistema em estado de alerta, risco de aquecimento";
    }
    else
    {
       std::cout << std::endl << "Sistema em estado estavel";
    }
    
};