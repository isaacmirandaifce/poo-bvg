#ifndef SENSORGPS_H
#define SENSORGPS_H

#include "Dispositivo.h"

class SensorGPS : virtual public Dispositivo {
private:
    double latitude;
    double longitude;

public:
    SensorGPS(std::string id, int tempo,
              double lat, double lon);

    void processarDados() override;

    void transmitirPayload();

    void transmitirPayload(std::string chaveCripto);

protected:
    double getLatitude();
    double getLongitude();
};

#endif