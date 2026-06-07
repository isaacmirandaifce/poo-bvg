#include <iostream>
#include <vector>
#include "Dispositivo.h"
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::vector<Dispositivo*> dispositivos;

    // Instanciando dinamicamente
    dispositivos.push_back(new SensorGPS("GPS-001", 1700000001, -3.7172, -38.5433));
    dispositivos.push_back(new SensorDiagnostico("OBD-001", 1700000002, 3500, 92.5));
    dispositivos.push_back(new SensorDiagnostico("OBD-002", 1700000003, 7200, 108.3));
    dispositivos.push_back(new RastreadorAvancado("RAV-001", 1700000004, -3.7200, -38.5400, 4500, 88.0));

    std::cout << "=== FleetTrack Pro - Processamento de Telemetria ===" << std::endl;
    std::cout << std::endl;

    // Polimorfismo dinamico
    for (Dispositivo* d : dispositivos) {
        d->processarDados();
        std::cout << std::endl;
    }

    // Sobrecarga de transmitirPayload
    std::cout << "=== Teste de Sobrecarga - SensorGPS ===" << std::endl;
    SensorGPS* gps = new SensorGPS("GPS-002", 1700000005, -3.7300, -38.5500);
    gps->transmitirPayload();
    gps->transmitirPayload("AES-256");

    // Liberando memoria
    for (Dispositivo* d : dispositivos) {
        delete d;
    }
    delete gps;

    return 0;
}