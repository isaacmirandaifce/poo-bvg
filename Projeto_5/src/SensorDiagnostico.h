#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H

#include "Dispositivo.h"

/**
 * Modulo de telemetria de motor (diagnostico OBD-II). Herda de Dispositivo
 * (heranca simples) e sobrescreve processarDados() para avaliar a saude
 * do motor com base em RPM e temperatura do fluido.
 */
class SensorDiagnostico : public Dispositivo {
private:
    int rpmMotor;
    double temperaturaFluido;

public:
    SensorDiagnostico(const std::string& id, int ts, int rpm, double temp);
    ~SensorDiagnostico() override;

    void processarDados() override;

    int getRpmMotor() const;
    double getTemperaturaFluido() const;
};

#endif // SENSORDIAGNOSTICO_H
