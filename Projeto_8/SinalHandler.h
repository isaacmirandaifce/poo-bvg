#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>

class SinalHandler {
public:
    static void inicializar();
    static bool sinalRecebido();
    static int getSinal();
private:
    static int ultimoSinal;
    static void tratador(int sinal);
};

#endif
