
#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>

class SistemaAcademico; 

class SinalHandler {
public:
    static void inicializar(SistemaAcademico* sistema);

private:
    static SistemaAcademico* sistema_ptr;
    static void tratador(int sinal);
};

#endif 