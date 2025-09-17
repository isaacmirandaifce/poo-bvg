#ifndef SINALHANDLER_H
#define SINALHANDLER_H


#include <csignal>
#include <functional>


class SinalHandler {
public:
// inicializar com uma funcao de callback que sera chamada no loop principal quando um sinal ocorrer
static void inicializar(std::function<void(int)> callback);
static volatile sig_atomic_t sinal_recebido;
static int ultimo_sinal;
private:
static void tratador(int sinal);
static std::function<void(int)> user_callback;
};


#endif // SINALHANDLER_H