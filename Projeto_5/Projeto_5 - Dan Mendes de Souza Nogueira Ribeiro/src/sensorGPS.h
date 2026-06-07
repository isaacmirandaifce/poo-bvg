#ifndef sensorGPS
#define sensorGPS
#include <iostream>
#include <string>
#include "dispositivo.h"

class SensorGPS : virtual public Dispositivo{
    private:
        double latitude;
        double longitude;
        
        public:

        void processarDados();

        void setLatitude(double newLat);
        void setLongitude(double newLon);

        double getLatitude();
        double getLongitude();

        void transmitirPayload();
        void transmitirPayload(std::string chaveCripto);
};

#endif