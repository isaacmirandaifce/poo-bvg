#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <iostream>
#include <string>

// Classe base abstrata para todos os dispositivos
class Dispositivo {
protected:
    // Informações comuns a qualquer dispositivo
    std::string idDispositivo;
    int timestamp;

public:
    Dispositivo(std::string id, int tempo);

    // Método virtual puro obriga as classes filhas a implementarem
    virtual void processarDados() = 0;

    // Destrutor virtual para evitar vazamento de memória
    virtual ~Dispositivo();
};

#endif