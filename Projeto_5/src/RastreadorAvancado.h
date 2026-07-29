#ifndef RASTREADOR_AVANCADO_H
#define RASTREADOR_AVANCADO_H

#include "SensorGPS.h"
#include "SensorDiagnostico.h"

class RastreadorAvancado : public SensorGPS, public SensorDiagnostico {
public:
    RastreadorAvancado(std::string id, int time, double lat, double lon, int rpm, double temp);

    void processarDados() override;
};

#endif // RASTREADOR_AVANCADO_H