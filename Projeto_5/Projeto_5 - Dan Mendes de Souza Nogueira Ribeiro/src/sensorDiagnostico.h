#ifndef sensorDiagnostico
#define sensorDiagnostico
#include <iostream>
#include <string>
#include "dispositivo.h"

class SensorDiagnostico : virtual public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    void processarDados();

    void setRPMMotor(int newRPM);
    void setTemperaturaFluido(double newTemflu);

    int getRPMMotor();
    double gettemperaturaFluido();
};
#endif