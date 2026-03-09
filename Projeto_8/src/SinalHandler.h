#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <functional>

class SinalHandler {
public:
    static void inicializar();
    static void registrarSalvar(const std::function<void()>& callbackSalvar);

private:
    static void tratador(int sinal);
    static std::function<void()> callback;
};

#endif
