#include <iostream>
#include <string>
#include "dispositivo.h"

class SensorGPS : public Dispositivo{
    private:
        double latitude;
        double longitude;
        
        public:

        void processarDados(){};

        void setLatitude(double newLat);
        void setLongitude(double newLon);

        double getLatitude();
        double getLongitude();
};