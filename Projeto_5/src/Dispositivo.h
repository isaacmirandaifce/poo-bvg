#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
protected:
    std::string idDispositivo;
    int timestamp;

public:
    Dispositivo(std::string idDispositivo, int timestamp);
    virtual ~Dispositivo();

    std::string getIdDispositivo() const;
    int getTimestamp() const;

    virtual void processarDados() = 0;
};

#endif