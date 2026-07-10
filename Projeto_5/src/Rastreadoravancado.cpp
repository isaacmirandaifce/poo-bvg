#include "RastreadorAvancado.h"
#include <iostream>
#include <iomanip>

// Inicializa cada classe pai com seus respectivos parâmetros.
// Como SensorGPS e SensorDiagnostico constroem Dispositivo separadamente,
// passei o mesmo id e ts para os dois para manter consistência.
RastreadorAvancado::RastreadorAvancado(const std::string& id, int ts,
                                       double lat, double lon,
                                       int rpm, double temp)
    : SensorGPS(id, ts, lat, lon),
      SensorDiagnostico(id, ts, rpm, temp) {}

RastreadorAvancado::~RastreadorAvancado() {
    std::cout << "[RastreadorAvancado] Destruindo hardware combinado.\n";
}

void RastreadorAvancado::processarDados() {
    std::cout << "====\n";
    std::cout << "[RastreadorAvancado] Relatório Consolidado\n";
    std::cout << "====\n";

    // Resolução explícita de escopo para evitar ambiguidade do Diamante
    std::cout << "  ID (GPS)        : " << SensorGPS::getId() << "\n";

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "  Latitude        : " << SensorGPS::getLatitude()  << "\n";
    std::cout << "  Longitude       : " << SensorGPS::getLongitude() << "\n";

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "  RPM do Motor    : " << SensorDiagnostico::getRpm()  << " rpm\n";
    std::cout << "  Temp. Fluido    : " << SensorDiagnostico::getTemp() << " °C\n";

    // Diagnóstico unificado
    if (SensorDiagnostico::getRpm() > 6000 || SensorDiagnostico::getTemp() > 100.0) {
        std::cout << "  STATUS: ATENÇÃO — Parâmetros fora do normal.\n";
    } else {
        std::cout << "  STATUS: Todos os sistemas operando normalmente.\n";
    }
    std::cout << "===========================================\n";
}