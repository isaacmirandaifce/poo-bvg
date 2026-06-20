#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <csignal>

class SignalHandler
{
public:
    static void inicializar();

private:
    static void tratador(int sinal);
};

#endif