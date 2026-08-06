#include "RastreadorAvancado.h"
#include <iostream>

RastreadorAvancado::RastreadorAvancado(const std::string& id, int ts,
                                        double lat, double lon,
                                        int rpm, double temp)
    // Lista de inicializacao: cada classe pai constroi o SEU proprio
    // subobjeto Dispositivo. A ordem de chamada segue a ordem de
    // declaracao da heranca (SensorGPS primeiro, depois SensorDiagnostico),
    // independentemente da ordem escrita aqui.
    : SensorGPS(id, ts, lat, lon),
      SensorDiagnostico(id, ts, rpm, temp) {}

RastreadorAvancado::~RastreadorAvancado() {
    std::cout << "[RastreadorAvancado] Encerrando rastreador avancado ID: "
              << getIdUnificado() << std::endl;
}

void RastreadorAvancado::processarDados() {
    // Resolucao de escopo explicita (Classe::membro) para evitar a
    // ambiguidade dos dois subobjetos Dispositivo herdados.
    std::cout << "[RASTREADOR AVANCADO] Dispositivo " << SensorGPS::getId()
              << " | Timestamp: " << SensorGPS::getTimestamp() << std::endl;

    std::cout << "  -> Geolocalizacao : (" << getLatitude() << ", "
              << getLongitude() << ")" << std::endl;
    std::cout << "  -> Diagnostico    : RPM=" << getRpmMotor()
              << " | Temp=" << getTemperaturaFluido() << "C" << std::endl;

    const bool alerta = (getRpmMotor() > 6000) || (getTemperaturaFluido() > 110.0);
    std::cout << "  -> Status Consolidado: " << (alerta ? "ALERTA" : "NORMAL")
              << std::endl;
}

std::string RastreadorAvancado::getIdUnificado() const {
    // static_cast escolhe explicitamente o subobjeto Dispositivo
    // alcancado via SensorGPS, eliminando a ambiguidade de heranca multipla.
    return static_cast<const SensorGPS*>(this)->getId();
}
