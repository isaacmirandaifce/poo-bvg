#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H
#include <csignal>
#include <iostream>

/**
 * @class SignalHandler
 * @brief Gerenciador de sinais do sistema operacional.
 * * Classe responsável por interceptar interrupções do sistema (como Ctrl+C ou encerramentos)
 * para permitir um desligamento seguro e log de emergência do sistema.
 */
class SignalHandler
{
public:
    /**
     * @brief Inicializa os escutadores de sinais.
     * * Registra a função de interceptação para lidar com os sinais SIGINT (Interrupção via teclado)
     * e SIGTERM (Sinal de término).
     */
    static void inicializar();

private:
    /**
     * @brief Método callback executado quando um sinal é recebido.
     * * Registra o evento de interrupção em um arquivo de log de emergência e encerra
     * a execução do programa de forma abrupta usando o código do sinal.
     * * @param sinal O código do sinal recebido pelo Sistema Operacional.
     */
    static void interceptar(int sinal);
};

#endif