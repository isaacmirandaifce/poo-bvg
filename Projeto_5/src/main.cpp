#include <iostream>
#include <vector>
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::cout << "Iniciando modulo de telemetria FleetTrack Pro...\n\n";

    // Vetor polimórfico
    std::vector<Dispositivo*> frota;

    // 1. Instanciando dinamicamente e alocando no vetor
    frota.push_back(new SensorGPS("GPS-10A", 1680000100, -23.5505, -46.6333));
    frota.push_back(new SensorDiagnostico("OBD-20B", 1680000105, 3200, 95.5));
    frota.push_back(new RastreadorAvancado("RAST-PRO", 1680000110, -22.9068, -43.1729, 2800, 92.0));

    // 2. Polimorfismo Dinâmico: Execução dos métodos através do ponteiro da classe base
    std::cout << "### PROCESSANDO DADOS DE TELEMETRIA ###\n";
    for (Dispositivo* disp : frota) {
        disp->processarDados();
        std::cout << std::endl;
    }

    // 3. Teste de Sobrecarga de Métodos no SensorGPS
    std::cout << "### TESTE DE SOBRECARGA (PAYLOAD) ###\n";
    // Usando dynamic_cast para acessar métodos específicos do GPS que não estão na classe base
    SensorGPS* gpsPtr = dynamic_cast<SensorGPS*>(frota[0]);
    if (gpsPtr != nullptr) {
        gpsPtr->transmitirPayload();               // Chamada sem parâmetro
        gpsPtr->transmitirPayload("A3F8-X99Z");    // Chamada com parâmetro (cripto)
    }
    std::cout << std::endl;

    // 4. Gerenciamento de Memória: Liberando os ponteiros
    std::cout << "Limpando memoria alocada...\n";
    for (Dispositivo* disp : frota) {
        delete disp;
    }
    frota.clear();

    std::cout << "Sistema finalizado com sucesso." << std::endl;
    return 0;
}