#ifndef SINAL_HANDLER_H
#define SINAL_HANDLER_H

#include <functional>

class SinalHandler {
public:
    static void configurar();
    static void setFuncaoSaida(std::function<void()> funcao);
};

#endif