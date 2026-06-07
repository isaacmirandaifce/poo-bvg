#ifndef rastreadorAvancado
#define rastreadorAvancado
#include <iostream>
#include <string>
#include "sensorDiagnostico.h"
#include "sensorGPS.h"

/**
 * @brief Classe de hardware combinado que executa múltiplas funções.
 * Implementa herança múltipla baseando-se no SensorDiagnostico e SensorGPS.
 */
class RastreadorAvancado : public SensorDiagnostico, public SensorGPS {

    public:
        /**
         * @brief Processa de forma unificada os dados de localização e diagnóstico do motor.
         */

        void processarDados();

};
#endif