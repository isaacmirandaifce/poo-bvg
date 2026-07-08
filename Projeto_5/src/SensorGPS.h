#ifndef SENSORGPS_H
#define SENSORGPS_H

#include "Dispositivo.h"

class SensorGPS : virtual public Dispositivo {
private:
    double latitude;
    double longitude;

public:
    SensorGPS(std::string id, int ts, double lat, double lon);
    ~SensorGPS() override;

    // Sobrescrita do método virtual puro
    void processarDados() override;

    // Sobrecarga de Métodos
    void transmitirPayload();
    void transmitirPayload(std::string chaveCripto);
};

#endif
