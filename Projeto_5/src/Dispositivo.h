#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
protected:
    std::string idDispositivo;
    int timestamp;

public:
    Dispositivo(std::string id, int ts);
    
    // Destrutor virtual para garantir a limpeza correta da memória nas subclasses
    virtual ~Dispositivo() = default; 
    
    // Método virtual puro: impede a instanciação direta desta classe
    virtual void processarDados() = 0; 
};

#endif