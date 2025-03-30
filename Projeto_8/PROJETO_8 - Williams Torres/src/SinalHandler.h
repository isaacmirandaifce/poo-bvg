#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include "Persistencia.h"

class SinalHandler {
public:
    static void inicializar();
private:
    static void tratador(int sinal);
};

#endif // SINALHANDLER_H