#include <iostream>
#include <vector>
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::vector<Dispositivo*> frota;

    // Instanciação dinâmica polimórfica
    frota.push_back(new SensorGPS("GPS-01", 1719830000, -3.7319, -38.5267));
    frota.push_back(new SensorDiagnostico("OBD-02", 1719830005, 3200, 91.5));
    frota.push_back(new RastreadorAvancado("FUSION-03", 1719830010, -3.7185, -38.5430, 4500, 98.2));

    std::cout << "=== PROCESSAMENTO POLIMÓRFICO DE TELEMETRIA ===" << std::endl;
    for (size_t i = 0; i < frota.size(); ++i) {
        frota[i]->processarDados();
        std::cout << "--------------------------------------------" << std::endl;
    }

    // Testando a Sobrecarga de Métodos (Polimorfismo Estático) no SensorGPS
    std::cout << "\n=== TESTE DE SOBRECARGA (PAYLOAD GPS) ===" << std::endl;
    SensorGPS* gpsRef = dynamic_cast<SensorGPS*>(frota[0]);
    if (gpsRef != nullptr) {
        gpsRef->transmitirPayload();
        gpsRef->transmitirPayload("KEY_SECURE_TOKEN_9988");
    }

    // Liberação de memória para evitar Memory Leaks
    for (size_t i = 0; i < frota.size(); ++i) {
        delete frota[i];
    }
    frota.clear();

    return 0;
}