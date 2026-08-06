#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

/**
 * Classe Base Abstrata do subsistema de telemetria do FleetTrack Pro.
 *
 * Define o contrato comum a todos os dispositivos de coleta de dados
 * instalados nos veiculos da frota (GPS, diagnostico de motor, etc.).
 *
 * Nao pode ser instanciada diretamente pois possui um metodo virtual
 * puro (processarDados), o que a torna uma classe abstrata em C++.
 */
class Dispositivo {
protected:
    std::string idDispositivo; // Identificador unico do dispositivo
    int timestamp;              // Instante (epoch/ciclo) da leitura

public:
    Dispositivo(const std::string& id, int ts);

    // Destrutor virtual: obrigatorio sempre que a classe sera usada
    // de forma polimorfica com ponteiros da classe base, para garantir
    // que o objeto derivado correto seja destruido (evita memory leak).
    virtual ~Dispositivo();

    // Metodo Virtual Puro -> torna Dispositivo uma classe abstrata.
    virtual void processarDados() = 0;

    // Acessores comuns, uteis para as classes derivadas que sofrem
    // heranca multipla e precisam desambiguar o acesso aos atributos.
    std::string getId() const;
    int getTimestamp() const;
};

#endif // DISPOSITIVO_H
