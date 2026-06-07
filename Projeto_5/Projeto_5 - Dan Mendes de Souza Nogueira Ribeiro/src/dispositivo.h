#ifndef dispositivo
#define dispositivo
#include <iostream>
#include <string>

class Dispositivo{

    protected:
        std::string idDispositivo;
        int timestamp;

    public:

    Dispositivo();
    virtual ~Dispositivo();
    virtual void processarDados() = 0;
};

#endif