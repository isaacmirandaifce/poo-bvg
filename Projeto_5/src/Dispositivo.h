#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>
#include <iostream>

class Dispositivo {
protected:
    std::string idDispositivo;
    int timestamp;

public:
    // Construtor
    Dispositivo(std::string id, int ts);

    // Destrutor Virtual
    virtual ~Dispositivo();

    // Método Virtual Puro
    virtual void processarDados() = 0;
};

#endif
