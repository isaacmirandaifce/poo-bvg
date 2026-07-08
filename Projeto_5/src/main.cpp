#include <iostream>
#include <vector>
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    // Vetor de ponteiros para a classe base
    std::vector<Dispositivo*> frota;

    // Instanciação de dispositivos (Alocação dinâmica)
    frota.push_back(new SensorGPS("GPS-001", 1001, -3.73, -38.52));
    frota.push_back(new SensorDiagnostico("OBD-99", 1002, 3000, 92.5));
    frota.push_back(new RastreadorAvancado("AVAN-77", 1003, -3.74, -38.53, 2500, 88.0));

    std::cout << "--- Processamento de Telemetria IoT ---\n";
    
    // Execução polimórfica: cada objeto sabe como processar seus dados
    for (Dispositivo* d : frota) {
        d->processarDados();
        
        // Exemplo de teste da sobrecarga no SensorGPS
        SensorGPS* gps = dynamic_cast<SensorGPS*>(d);
        if (gps) {
            gps->transmitirPayload("CHAVE_SEGURA_2026");
        }
        std::cout << "---------------------------------------\n";
    }

    // Liberação de memória
    std::cout << "\n[Sistema] Iniciando limpeza de memória...\n";
    for (Dispositivo* d : frota) {
        delete d;
    }
    frota.clear();

    return 0;
}
