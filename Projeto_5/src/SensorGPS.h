#ifndef SENSORGPS_H
#define SENSORGPS_H

#include "Dispositivo.h"
#include <string>

class SensorGPS : public Dispositivo {
private:
    double latitude;
    double longitude;

public:
    SensorGPS(std::string idDispositivo, int timestamp, double latitude, double longitude);

    void processarDados() override;

    void transmitirPayload();
    void transmitirPayload(std::string chaveCripto);
};

#endif