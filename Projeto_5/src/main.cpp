#include <iostream>
#include <vector>
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::cout << "--- Inicializando Sistema FleetTrack Pro ---\n" << std::endl;

    // Coleção polimórfica (Vetor de ponteiros da classe base)
    std::vector<Dispositivo*> frota;

    // Instanciando dinamicamente e armazenando
    frota.push_back(new SensorGPS("GPS-001", 1700000100, -23.5505, -46.6333));
    frota.push_back(new SensorDiagnostico("DIAG-002", 1700000105, 3200, 92.5));
    frota.push_back(new RastreadorAvancado("ADV-003", 1700000110, -22.9068, -43.1729, 2800, 88.0));

    // Iteração polimórfica
    for (Dispositivo* disp : frota) {
        disp->processarDados(); // Chamada resolvida em runtime (late binding)

        // Verificando dinamicamente se é um SensorGPS para demonstrar a sobrecarga
        SensorGPS* gps = dynamic_cast<SensorGPS*>(disp);
        if (gps) {
            gps->transmitirPayload();
            gps->transmitirPayload("FLEET_SECURE_KEY_99");
        }
        std::cout << "------------------------------------------" << std::endl;
    }

    // Gerenciamento de Memória: Prevenção de Memory Leaks
    for (Dispositivo* disp : frota) {
        delete disp; // Invoca o destrutor virtual corretamente
    }
    frota.clear();

    std::cout << "Sistema encerrado com sucesso. Memória liberada." << std::endl;
    return 0;
}