#ifndef RASTREADORAVANCADO_H
#define RASTREADORAVANCADO_H


#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include <string>

// Herança Múltipla: combina geolocalização + telemetria de motor.
// Ambas as classes pai herdam de Dispositivo, gerando o
// "Problema do diamante". Tratei a ambiguidade chamando
// explicitamente os membros de cada escopo pai nos métodos.
class RastreadorAvancado : public SensorGPS, public SensorDiagnostico {
public:
    // O construtor inicializa ambas as classes pai
    // Obs: Dispositivo será construído 2x (uma por cada pai),
    // pois não usamos herança virtual aqui — conforme o escopo do projeto.
    RastreadorAvancado(const std::string& id, int ts,
                       double lat, double lon,
                       int rpm, double temp);
 
    ~RastreadorAvancado() override;
    
    // Sobrescrita que unifica saída de diagnóstico e localização
    void processarDados() override;
    };

#endif