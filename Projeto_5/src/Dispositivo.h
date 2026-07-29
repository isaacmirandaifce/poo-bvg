#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
protected:
    std::string idDispositivo;
    int timestamp;

public:
    Dispositivo(std::string id, int time);
    virtual ~Dispositivo();

    // Método virtual puro (torna a classe abstrata)
    virtual void processarDados() = 0;
};

#endif // DISPOSITIVO_H