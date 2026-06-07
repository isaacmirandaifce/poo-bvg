#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H

#include "Dispositivo.h"
#include <string>

class SensorDiagnostico : public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    SensorDiagnostico(std::string id, int ts, int rpm, double temp);
    void processarDados() override;
};

#endif