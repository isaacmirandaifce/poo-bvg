#include <iostream>
#include <string>
#include <vector>
#include "sensorDiagnostico.h"
#include "sensorGPS.h"
#include "rastreadorAvancado.h"

int main(){

    std::vector<Dispositivo *> vetorDispositivo;

    SensorDiagnostico* sensorDia = new SensorDiagnostico;

    sensorDia->setRPMMotor(6100);
    sensorDia->setTemperaturaFluido(80.00);
    vetorDispositivo.push_back(sensorDia);

    SensorGPS *sensorGps = new SensorGPS;

    sensorGps->setLatitude(-900.00);
    sensorGps->setLongitude(-800.00);
    vetorDispositivo.push_back(sensorGps);

    RastreadorAvancado *rasAvancado = new RastreadorAvancado();
    rasAvancado->setRPMMotor(5500);
    rasAvancado->setTemperaturaFluido(92.2);
    rasAvancado->setLatitude(550.51);
    rasAvancado->setLongitude(-124.00);
    vetorDispositivo.push_back(rasAvancado);

    for (int i = 0; i < vetorDispositivo.size(); i++)
    {

        vetorDispositivo[i]->processarDados();
    }

    std::cout << std::endl;

    SensorGPS testeGPS;

    testeGPS.transmitirPayload();

    testeGPS.transmitirPayload("CHAVETESTE");

    for (int i = 0; i < vetorDispositivo.size(); i++)
    {

        delete (vetorDispositivo[i]);
    }

    return 0;
}