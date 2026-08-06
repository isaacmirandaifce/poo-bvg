#ifndef RASTREADORAVANCADO_H
#define RASTREADORAVANCADO_H

#include "SensorGPS.h"
#include "SensorDiagnostico.h"

/**
 * Hardware combinado de alta performance: fusiona geolocalizacao (SensorGPS)
 * e telemetria de motor (SensorDiagnostico) atraves de Heranca Multipla.
 *
 * ATENCAO - Problema do Diamante:
 * Como SensorGPS e SensorDiagnostico herdam (nao-virtualmente) de
 * Dispositivo, RastreadorAvancado passa a conter DOIS subobjetos
 * Dispositivo distintos (um vindo de cada ramo). Por isso:
 *   - Nao acessamos idDispositivo/timestamp diretamente aqui (seria ambiguo).
 *   - Usamos Resolucao de Escopo explicita (Classe::membro) para indicar
 *     de qual ramo queremos o dado.
 *   - No main.cpp, ao guardar um RastreadorAvancado* em um
 *     std::vector<Dispositivo*>, e necessario um static_cast explicito
 *     escolhendo um dos dois caminhos de heranca (SensorGPS ou
 *     SensorDiagnostico), pois a conversao implicita seria ambigua.
 */
class RastreadorAvancado : public SensorGPS, public SensorDiagnostico {
public:
    RastreadorAvancado(const std::string& id, int ts,
                        double lat, double lon,
                        int rpm, double temp);
    ~RastreadorAvancado() override;

    // Sobrescreve processarDados() unificando a saida de localizacao e
    // diagnostico. Como a assinatura e identica em ambos os ramos da
    // heranca, esta unica sobrescrita satisfaz o contrato virtual dos
    // dois subobjetos Dispositivo simultaneamente.
    void processarDados() override;

    // Retorna o ID do dispositivo desambiguando explicitamente via
    // static_cast para o subobjeto SensorGPS.
    std::string getIdUnificado() const;
};

#endif // RASTREADORAVANCADO_H
