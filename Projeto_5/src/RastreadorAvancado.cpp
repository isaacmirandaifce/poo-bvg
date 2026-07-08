#include "RastreadorAvancado.h"

// Inicialização dos construtores da classe pai
RastreadorAvancado::RastreadorAvancado(std::string id, int ts, double lat, double lon, int rpm, double temp)
    : Dispositivo(id, ts), // Chama explicitamente a base
      SensorGPS(id, ts, lat, lon), 
      SensorDiagnostico(id, ts, rpm, temp) {}

RastreadorAvancado::~RastreadorAvancado() {
    std::cout << "[Memoria] Destruindo RastreadorAvancado (Herança Múltipla).\n";
}

void RastreadorAvancado::processarDados() {
    std::cout << "[SISTEMA AVANÇADO] Unificando telemetria:\n";
    SensorGPS::processarDados();
    SensorDiagnostico::processarDados();
}
