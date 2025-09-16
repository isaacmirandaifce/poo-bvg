#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <atomic>
#include <functional>

class SinalHandler {
    static std::atomic<bool> ativo;
    static std::function<void(int)> callbackSeguro;
    static void tratador(int sinal);
public:
    static void inicializar();
    static void registrarCallbackSeguro(std::function<void(int)> cb);
    static bool estaAtivo();
};

#endif // SINALHANDLER_H
