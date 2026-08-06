#ifndef SENSORGPS_H
#define SENSORGPS_H

#include "Dispositivo.h"
#include <string>

/**
 * Modulo de geolocalizacao. Herda de Dispositivo (heranca simples)
 * e sobrescreve processarDados() para formatar coordenadas geograficas.
 *
 * Tambem demonstra Sobrecarga de Metodos (polimorfismo estatico) atraves
 * de duas versoes de transmitirPayload().
 */
class SensorGPS : public Dispositivo {
private:
    double latitude;
    double longitude;

public:
    SensorGPS(const std::string& id, int ts, double lat, double lon);
    ~SensorGPS() override;

    // Sobrescrita (override) do metodo virtual puro da classe base.
    void processarDados() override;

    // --- Sobrecarga de Metodos (Polimorfismo Estatico) ---
    void transmitirPayload();                              // texto puro
    void transmitirPayload(const std::string& chaveCripto); // transmissao segura

    double getLatitude() const;
    double getLongitude() const;
};

#endif // SENSORGPS_H
