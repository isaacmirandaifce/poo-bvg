#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H

#include "Dispositivo.h"
#include <string>

class SensorDiagnostico : public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    SensorDiagnostico(std::string idDispositivo, int timestamp, int rpmMotor, double temperaturaFluido);

    void processarDados() override;
};

#endif