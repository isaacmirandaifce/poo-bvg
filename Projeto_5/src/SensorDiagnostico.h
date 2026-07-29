#ifndef SENSOR_DIAGNOSTICO_H
#define SENSOR_DIAGNOSTICO_H

#include "Dispositivo.h"

class SensorDiagnostico : virtual public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    SensorDiagnostico(std::string id, int time, int rpm, double temp);
    
    void processarDados() override;
};

#endif // SENSOR_DIAGNOSTICO_H