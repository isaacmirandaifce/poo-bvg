#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <csignal>

class SignalHandler {
public:
    static void inicializar();

private:
    static void tratador(int sinal);
};

#endif 