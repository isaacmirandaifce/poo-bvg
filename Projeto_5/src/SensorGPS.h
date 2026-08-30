#ifndef SENSORGPS_H
#define SENSORGPS_H

#include "Dispositivo.h"
#include <string>

// Herança virtual para prevenir o problema do diamante na herança múltipla
class SensorGPS : virtual public Dispositivo {
private:
    double latitude;
    double longitude;

public:
    SensorGPS(std::string id, int ts, double lat, double lon);
    
    void processarDados() override;
    
    // Sobrecarga de Métodos (Polimorfismo Estático)
    void transmitirPayload();
    void transmitirPayload(std::string chaveCripto);
};

#endif