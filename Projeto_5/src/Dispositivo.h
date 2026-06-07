#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
protected:
    std::string idDispositivo;
    int timestamp;

public:
    Dispositivo(std::string id, int ts);
    virtual ~Dispositivo();
    virtual void processarDados() = 0;
};

#endif