#include <csignal>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "signalHandler.h"

void SignalHandler::inicializar(){

    std::signal(SIGINT, interceptar);

    std::signal(SIGTERM, interceptar);
};

void SignalHandler::interceptar(int sinal)
{
    std::cout << "Alerta critico: " << sinal << std::endl;

    std::ofstream arquivoLog("log_emergencia.txt", std::ios::app);
    
    if (arquivoLog.is_open()){
        arquivoLog << "Sistema foi interrompido, causa: " << sinal << std::endl;
        arquivoLog.close();
    }

    std::exit(sinal);
};