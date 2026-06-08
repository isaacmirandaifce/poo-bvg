#include <iostream>
#include <vector>

#include "Dispositivo.h"
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::vector<Dispositivo*> dispositivos;

    dispositivos.push_back(new SensorGPS("GPS-001", 1001, -5.0845, -39.3703));
    dispositivos.push_back(new SensorDiagnostico("DIAG-001", 1002, 2500, 92.5));

    SensorGPS gpsSobrecarga("GPS-002", 1003, -5.1000, -39.4000);

    std::cout << "=== Teste de Sobrecarga de Metodos ===" << std::endl;
    gpsSobrecarga.transmitirPayload();
    gpsSobrecarga.transmitirPayload("CHAVE-SEGURA-123");

    std::cout << "\n=== Processamento Polimorfico ===" << std::endl;

    for (Dispositivo* dispositivo : dispositivos) {
        std::cout << "\n-----------------------------" << std::endl;
        dispositivo->processarDados();
    }

    std::cout << "\n=== Heranca Multipla ===" << std::endl;

    RastreadorAvancado rastreador(
        "RAST-001",
        1004,
        -5.2000,
        -39.5000,
        3100,
        105.8
    );

    rastreador.processarDados();

    for (Dispositivo* dispositivo : dispositivos) {
        delete dispositivo;
    }

    dispositivos.clear();

    return 0;
}