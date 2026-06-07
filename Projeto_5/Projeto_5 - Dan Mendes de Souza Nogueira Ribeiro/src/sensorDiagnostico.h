#include <iostream>
#include <string>
#include "dispositivo.h"

class SensorDiagnostico : public Dispositivo{
    private:
        int rpmMotor;
        double temperaturaFluido;
    
    public:
        void processarDados();

        void setRPMMotor(int newRPM);
        void setTemperaturaFluido(double newTemflu);

        int getRPMMotor();
        double gettemperaturaFluido();
};