#include "SignalHandler.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <csignal>
#include <ctime> 

void SignalHandler::inicializar() {
    std::signal(SIGINT, SignalHandler::tratador); 
    std::signal(SIGTERM, SignalHandler::tratador);  
}

void SignalHandler::tratador(int sinal) {
    std::cerr << "\n\n[ALERTA CRITICO] Sinal " << sinal 
              << " recebido pelo Sistema Operacional!" << std::endl;

    std::ofstream logEmergency("emergency_shutdown.log", std::ios::app);
    if (logEmergency.is_open()) {
        // Obtém o tempo atual e converte para struct tm
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* localTime = std::localtime(&now);

        // Formata a data/hora usando um buffer de texto tradicional
        char bufferTime[80];
        std::strftime(bufferTime, sizeof(bufferTime), "%Y-%m-%d %H:%M:%S", localTime);

        logEmergency << "[" << bufferTime 
                     << "] Interrupcao forcada capturada via sinal: " << sinal << "\n";
        logEmergency.flush();
        logEmergency.close();
        std::cout << "[EMERGENCY] Log de encerramento gravado com sucesso em 'emergency_shutdown.log'." << std::endl;
    }

    std::cout << "[ENGINE] Buffers descarregados e recursos liberados limpos." << std::endl;
    std::cout << "[ENGINE] Finalizando processo de forma segura...\n" << std::endl;

    std::exit(sinal);
}