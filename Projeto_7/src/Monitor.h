#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <string>

/* Classe Base */
class Dispositivo {
public:
    /* Método virtual para permitir a sobrecarga nas classes derivadas */
    virtual void ligar() {
        std::cout << "Dispositivo ligado!" << std::endl;
    }

    virtual void desligar() {
        std::cout << "Dispositivo desligado!" << std::endl;
    }

    /* Destruidor virtual para garantir o comportamento correto com herança */
    virtual ~Dispositivo() = default;
};

/* Classe Derivada */
class Monitor : public Dispositivo {
public:
    /* Sobrescreve o método ligar da classe base */
    void ligar() override {
        std::cout << "Monitor ligado!" << std::endl;
    }

    /* Sobrescreve o método desligar da classe base */
    void desligar() override {
        std::cout << "Monitor desligado!" << std::endl;
    }
};

#endif // MONITOR_H
