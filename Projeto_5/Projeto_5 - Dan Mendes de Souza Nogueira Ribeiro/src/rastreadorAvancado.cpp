#include <iostream>
#include <string>
#include "sensorDiagnostico.h"
#include "sensorGPS.h"
#include "rastreadorAvancado.h"

void RastreadorAvancado::processarDados() {

    SensorGPS::processarDados();
    SensorDiagnostico::processarDados();
};