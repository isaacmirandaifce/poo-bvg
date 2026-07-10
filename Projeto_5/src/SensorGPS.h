#ifndef SENSORGPS_H
#define SENSORGPS_H


#include "Dispositivo.h"
#include <string>

class SensorGPS : public Dispositivo {
    private:
        double latitude;
        double longitude;

    public:
        SensorGPS(const std::string& id , int ts, double lat, double long);
        virtual ~SensorGPS();

        //Sobreescrevendo o método virtual puro
        void processarDados() override;

        //Sobrecarga de transmitirPayload (Polimorfismo estático)
        void transmitirPayload();        //transmissão aberta (texto puro)
        void transmitirPayload(std::string chaveCripto);        //transmissão segura (com assinatura)

        // Getters -necessários para o RastreadorAvancado
        double getLatitude() const;
        double getLongitude() const;
    };

    #endif 
