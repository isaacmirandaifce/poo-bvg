#ifndef RASTREADORAVANCADO_H
#define RASTREADORAVANCADO_H

#include "SensorGPS.h"
#include "SensorDiagnostico.h"

class RastreadorAvancado : public SensorGPS, public SensorDiagnostico {
    public:
        RastreadorAvancado(std::string id, int ts, double lat, double lon, int rpm, double temp);

        void processarDados() override;
};

#endif