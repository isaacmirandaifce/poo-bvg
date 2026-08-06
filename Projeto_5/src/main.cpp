#include <iostream>
#include <vector>
#include "Dispositivo.h"
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::cout << "===== FleetTrack Pro - Subsistema de Telemetria IoT =====\n" << std::endl;

    // Polimorfismo Dinamico: coletamos dispositivos heterogeneos usando
    // um unico vetor de ponteiros da classe base abstrata.
    std::vector<Dispositivo*> frota;

    frota.push_back(new SensorGPS("GPS-001", 1001, -3.850000, -40.870000));
    frota.push_back(new SensorDiagnostico("OBD-002", 1002, 3200, 92.5));

    RastreadorAvancado* rastreador =
        new RastreadorAvancado("RAV-003", 1003, -3.100000, -60.020000, 6500, 115.0);

    // Heranca multipla nao-virtual gera dois caminhos possiveis para
    // Dispositivo*. Escolhemos explicitamente o caminho via SensorGPS
    // com static_cast em duas etapas para evitar erro de ambiguidade
    // em tempo de compilacao.
    frota.push_back(static_cast<Dispositivo*>(static_cast<SensorGPS*>(rastreador)));

    std::cout << "--- Processamento polimorfico via Dispositivo* ---\n" << std::endl;
    for (Dispositivo* d : frota) {
        d->processarDados(); // despachado dinamicamente (virtual)
        std::cout << "-------------------------------------------------" << std::endl;
    }

    // --- Sobrecarga de Metodos (Polimorfismo Estatico) ---
    std::cout << "\n--- Demonstracao de Sobrecarga (transmitirPayload) ---\n" << std::endl;
    SensorGPS gpsDemo("GPS-DEMO", 2000, 10.500000, 20.500000);
    gpsDemo.transmitirPayload();
    gpsDemo.transmitirPayload("chave-secreta-2024");

    // --- Liberacao de memoria ---
    // Como Dispositivo possui destrutor virtual, delete via Dispositivo*
    // aciona corretamente o destrutor mais derivado de cada objeto
    // (inclusive RastreadorAvancado, com ajuste automatico de offset
    // do ponteiro pelo compilador), evitando vazamento de memoria.
    std::cout << "\n--- Liberando memoria (destrutores virtuais) ---\n" << std::endl;
    for (Dispositivo* d : frota) {
        delete d;
    }
    frota.clear();

    std::cout << "\nExecucao finalizada sem vazamentos de memoria." << std::endl;
    return 0;
}
