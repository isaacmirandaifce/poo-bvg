#include <iostream>
#include <string>
#include "sensorGPS.h"

void SensorGPS::processarDados()
{
    double latitude = this->latitude;
    double longitude = this->longitude;

    if (latitude >= 0)
    {
        std::cout << "A Latidude: " << std::endl << latitude << " N" << std::endl;
    }
    else
    {
        std::cout << "A Latidude: " << std::endl << latitude << " S" << std::endl;
    }

    if (longitude >= 0)
    {
        std::cout << "A Longitude: " << std::endl << longitude << " E" << std::endl;
    }
    else
    {
        std::cout << "A Longitude: " << std::endl << longitude << " W" << std::endl;
    }
};

void SensorGPS::transmitirPayload(){
    std::cout << std::endl << "Transmitindo os dados abertos em texto puro." << std::endl;
};

void SensorGPS::transmitirPayload(std::string chaveCripto) {
        std::cout << std::endl << "Utilizando a chave "<< chaveCripto << " para a transmissão." << std::endl;

};

void SensorGPS::setLatitude(double newLat){ this->latitude = newLat;};
void SensorGPS::setLongitude(double newLon) { this->longitude = newLon; };

double SensorGPS::getLatitude() {return this->latitude;};
double SensorGPS::getLongitude() {return this->longitude;};

