#ifndef sensorDiagnostico
#define sensorDiagnostico
#include <iostream>
#include <string>
#include "dispositivo.h"

/**
 * @brief Classe que representa um sensor de diagnóstico de motor.
 * Herda de Dispositivo de forma virtual para prevenir o problema do diamante.
 */
class SensorDiagnostico : virtual public Dispositivo {
private:
    /** @brief Rotações por minuto atuais do motor. */
    int rpmMotor;
    /** @brief Temperatura atual do fluido de arrefecimento em graus Celsius. */
    double temperaturaFluido;

public:
    /**
     * @brief Avalia os dados de RPM e temperatura, alertando sobre estados críticos.
     */
    void processarDados();

    /**
     * @brief Define o valor de RPM do motor.
     * @param newRPM Novo valor numérico para as rotações por minuto.
     */
    void setRPMMotor(int newRPM);

    /**
     * @brief Define o valor da temperatura do fluido.
     * @param newTemflu Novo valor de temperatura.
     */
    void setTemperaturaFluido(double newTemflu);

    /**
     * @brief Obtém o valor de RPM do motor.
     * @return Inteiro contendo o RPM atual.
     */
    int getRPMMotor();

    /**
     * @brief Obtém a temperatura atual do fluido.
     * @return Double contendo a temperatura.
     */
    double gettemperaturaFluido();
};
#endif