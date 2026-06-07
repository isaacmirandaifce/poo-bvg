#ifndef rastreadorAvancado
#define rastreadorAvancado
#include <iostream>
#include <string>
#include "sensorDiagnostico.h"
#include "sensorGPS.h"

class RastreadorAvancado : public SensorDiagnostico, public SensorGPS {

    public:
    
    void processarDados();

};
#endif