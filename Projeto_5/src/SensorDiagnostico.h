#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H

#include "Dispositivo.h"

class SensorDiagnostico : public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    SensorDiagnostico(std::string id, int ts, int rpm, double temp);
    ~SensorDiagnostico() override;

    // Sobrescrita do método virtual puro
    void processarDados() override;
};

#endif
