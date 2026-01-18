#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <functional>

class SinalHandler {
public:
    using Handler = std::function<void()>;
    static void inicializar();
    static void setShutdownHandler(Handler h);
private:
    static void tratador(int sinal);
    static Handler shutdownHandler;
};

#endif // SINALHANDLER_H
