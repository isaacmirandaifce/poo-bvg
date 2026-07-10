#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <csignal>
#include <iostream>

class SignalHandler {
public:
    //Registra os hooks de SIGINT e SIGTERM no SO
    static void inicializar();

private:
    //Tratador estático: único formato aceito por std::signal()
    static void tratador(int sinal);
};

#endif