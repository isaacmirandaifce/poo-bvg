#include <iostream>
#include <string>
#include <vector>
#include "sensorDiagnostico.h"
#include "sensorGPS.h"
#include "rastreadorAvancado.h"

int main(){

    std::vector<Dispositivo *> vetorDispositivo;

    vetorDispositivo.push_back(new SensorDiagnostico);

    vetorDispositivo.push_back(new SensorGPS);

    vetorDispositivo.push_back(new RastreadorAvancado);

    for (int i = 0; i < vetorDispositivo.size(); i++)
    {

        vetorDispositivo[i]->processarDados();
    }

    for (int i = 0; i < vetorDispositivo.size(); i++)
    {

        delete (vetorDispositivo[i]);
    }

    return 0;
}