#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include <functional>

class SinalHandler {
public:
    // Inicializa a captura de sinais
    static void inicializar();

    // Permite registrar uma ação a ser tomada antes de encerrar
    static void definirCallbackDeSaida(std::function<void()> callback);

private:
    static void tratador(int sinal);
    static std::function<void()> callbackDeSaida;
};

#endif // SINALHANDLER_H
