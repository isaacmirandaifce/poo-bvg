#include <iostream>
#include <vector>
#include "SensorGPS.h"
#include "SensorDiagnostico.h"
#include "RastreadorAvancado.h"

int main() {
    std::cout << "\n===== FleetTrack Pro — Motor de Telemetria IoT =====\n\n";

    // Vetor de ponteiros para a classe base (Polimorfismo dinâmico)
    // Permite armazenar qualquer subclasse de Dispositivo
    std::vector<Dispositivo*> frota;

    // Instanciação dinâmica com new — memória no heap
    frota.push_back(new SensorGPS("GPS-001", 1718000001, -3.7172, -38.5434));
    frota.push_back(new SensorGPS("GPS-002", 1718000002, -3.7311, -38.5266));
    frota.push_back(new SensorDiagnostico("OBD-001", 1718000003, 3200, 89.5));
    frota.push_back(new SensorDiagnostico("OBD-002", 1718000004, 6500, 105.0)); // RPM crítico
    // RastreadorAvancado herda Dispositivo por dois caminhos (Problema do Diamante).
    // Usei static_cast para resolver a ambiguidade, escolhendo o caminho via SensorGPS.
    RastreadorAvancado* adv = new RastreadorAvancado("ADV-001", 1718000005,
                                                     -3.7450, -38.5200,
                                                     4100, 92.3);
    frota.push_back(static_cast<SensorGPS*>(adv));
    

    // Laço (Polimorfismo): o compilador resolve qual processarDados() chamar
    // em tempo de execução via vtable (despacho virtual)
    std::cout << "--- Processando dados de todos os dispositivos ---\n\n";
    for (Dispositivo* d : frota) {
        d->processarDados();
        std::cout << "\n";
    }

    // Demonstração da Sobrecarga de transmitirPayload (Polimorfismo estático)
    std::cout << "--- Demonstração de Sobrecarga (SensorGPS) ---\n\n";
    SensorGPS sensorDemo("GPS-DEMO", 1718000099, -3.7200, -38.5300);
    sensorDemo.transmitirPayload();                   // Versão aberta
    sensorDemo.transmitirPayload("AES256-K3YX0P");   // Versão segura com chave

    std::cout << "\n--- Liberando memória (delete + destrutor virtual) ---\n\n";

    // Gerenciamento de memória: delete chama o destrutor correto
    // graças ao virtual ~Dispositivo() na classe base
    for (Dispositivo* d : frota) {
        delete d;
    }
    frota.clear();

    std::cout << "\n==== Processamento finalizado com sucesso ====\n";
    return 0;
}