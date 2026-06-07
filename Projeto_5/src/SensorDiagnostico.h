#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H

#include "Dispositivo.h"

class SensorDiagnostico : virtual public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    SensorDiagnostico(std::string id,
                      int tempo,
                      int rpm,
                      double temperatura);

    void processarDados() override;

protected:
    int getRpmMotor();
    double getTemperatura();
};

#endif