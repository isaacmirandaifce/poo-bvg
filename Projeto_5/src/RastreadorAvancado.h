#ifndef RASTREADORAVANCADO_H
#define RASTREADORAVANCADO_H

#include "SensorGPS.h"
#include "SensorDiagnostico.h"

// Herança Múltipla
class RastreadorAvancado : public SensorGPS, public SensorDiagnostico {
public:
    RastreadorAvancado(std::string id, int ts, double lat, double lon, int rpm, double temp);
    ~RastreadorAvancado() override;

    // Sobrescrita que unifica as saídas
    void processarDados() override;
};

#endif
