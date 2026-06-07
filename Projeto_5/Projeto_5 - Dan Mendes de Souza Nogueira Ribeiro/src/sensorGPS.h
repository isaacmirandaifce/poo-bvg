#ifndef sensorGPS
#define sensorGPS
#include <iostream>
#include <string>
#include "dispositivo.h"

/**
 * @brief Classe que representa um sensor de geolocalização.
 * Herda de Dispositivo de forma virtual para prevenir o problema do diamante.
 */
class SensorGPS : virtual public Dispositivo{
    private:
        /** @brief Coordenada geográfica de latitude. */
        double latitude;
        /** @brief Coordenada geográfica de longitude. */
        double longitude;
        
    public:
        
        /**
         * @brief Processa e imprime as coordenadas geográficas formatadas.
         */
        void processarDados();

        /**
         * @brief Define a coordenada de latitude.
         * @param newLat Novo valor em graus para a latitude.
         */
        void setLatitude(double newLat);
        
        /**
         * @brief Define a coordenada de longitude.
         * @param newLon Novo valor em graus para a longitude.
         */
        void setLongitude(double newLon);

        /**
         * @brief Retorna a latitude atual.
         * @return Double contendo a latitude.
         */
        double getLatitude();

        /**
         * @brief Retorna a longitude atual.
         * @return Double contendo a longitude.
         */
        double getLongitude();

        /**
         * @brief Transmite o payload de dados de forma aberta em texto puro.
         */
        void transmitirPayload();

        /**
         * @brief Transmite o payload de dados utilizando segurança estática.
         * @param chaveCripto String contendo a chave de criptografia ou assinatura.
         */
        void transmitirPayload(std::string chaveCripto);
};

#endif