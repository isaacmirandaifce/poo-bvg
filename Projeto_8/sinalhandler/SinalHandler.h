#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>

class SinalHandler {
public:
    // Inicializa o tratador de sinais
    static void inicializar();

private:
    // Função que lida com sinais recebidos
    static void tratador(int sinal);
};

#endif
