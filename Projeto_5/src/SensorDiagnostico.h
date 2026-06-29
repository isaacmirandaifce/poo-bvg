#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H

#include "Dispositivo.h"

class SensorDiagnostico : virtual public Dispositivo {
    private:
        int rpmMotor;
        double temperaturaFluido;

    public:
        SensorDiagnostico(std::string id, int ts, int rpm, double temp);

        void processarDados() override;
};

#endif