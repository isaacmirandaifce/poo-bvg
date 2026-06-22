#include <csignal>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "signalHandler.h"

void SignalHandler::inicializar()
{
    // Mapeia os sinais do sistema para o método de interceptação interno.
    std::signal(SIGINT, interceptar);
    std::signal(SIGTERM, interceptar);
};

void SignalHandler::interceptar(int sinal)
{
    std::cout << "Alerta critico: " << sinal << std::endl;

    // Tenta registrar a causa da interrupção em um log de emergência.
    std::ofstream arquivoLog("log_emergencia.txt", std::ios::app);

    if (arquivoLog.is_open())
    {
        arquivoLog << "Sistema foi interrompido, causa: " << sinal << std::endl;
        arquivoLog.close();
    }

    // Finaliza o programa retornando o código do sinal.
    std::exit(sinal);
};