#ifndef RASTREADORAVANCADO_H
#define RASTREADORAVANCADO_H

#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include <string>

class RastreadorAvancado : public SensorGPS, public SensorDiagnostico {
public:
    RastreadorAvancado(
        std::string idDispositivo,
        int timestamp,
        double latitude,
        double longitude,
        int rpmMotor,
        double temperaturaFluido
    );

    void processarDados() override;
};

#endif