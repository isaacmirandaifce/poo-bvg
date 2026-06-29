#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
    protected:
        std::string idDispositivo;
        int timestamp;

    public:
        Dispositivo(std::string id, int ts);

    // Destrutor virtual para evitar memory leaks
        virtual ~Dispositivo() = default;

        virtual void processarDados() = 0;
};

#endif