#ifndef SENSORDIAGNOSTICO_H
#define SENSORDIAGNOSTICO_H


#include "Dispositivo.h"
#include <string>

class SensorDiagnostico : public Dispositivo {
private: 
    int rpmMotor;
    double temperaturafluido;

public:
    SensorDiagnostico(const std::string& id, int ts, int rpm, double temp);
    virtual ~SensorDiagnostico();

    //Sobrescrita do método virtual puro
    void processarDados() override;

    //Getters - necessários para o RastreadorAvancado
    int getRpm() const;
    double getTemp() const;
};

#endif