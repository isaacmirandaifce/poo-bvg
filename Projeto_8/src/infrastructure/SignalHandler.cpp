#include "SignalHandler.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

void SignalHandler::inicializar()
{
    signal(SIGINT, tratador);
    signal(SIGTERM, tratador);
}

void SignalHandler::tratador(int sinal)
{
    std::cerr << "\n[ALERTA] Sinal recebido: "
              << sinal
              << std::endl;

    std::ofstream log("emergency.log", std::ios::app);

    if (log.is_open())
    {
        log << "Encerramento seguro. Sinal recebido: "
            << sinal
            << std::endl;

        log.flush();
        log.close();
    }

    std::cerr << "[ALERTA] Sistema encerrado com seguranca."
              << std::endl;

    exit(sinal);
}