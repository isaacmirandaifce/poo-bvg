#ifndef SENSOR_GPS_H
#define SENSOR_GPS_H

#include "Dispositivo.h"

class SensorGPS : virtual public Dispositivo {
private:
    double latitude;
    double longitude;

public:
    SensorGPS(std::string id, int time, double lat, double lon);
    
    void processarDados() override;

    // Sobrecarga de métodos (Polimorfismo Estático)
    void transmitirPayload();
    void transmitirPayload(std::string chaveCripto);
};

#endif // SENSOR_GPS_H