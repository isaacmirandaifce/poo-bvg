#include "SignalHandler.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void SignalHandler::inicializar() {
    // Registra os hooks de sinal do Sistema Operacional
    std::signal(SIGINT, SignalHandler::tratador);
    std::signal(SIGTERM, SignalHandler::tratador);
}

void SignalHandler::tratador(int sinal) {
    std::cerr << "\n[CRITICAL ALERT] Sinal de interrupcao recebido (" << sinal << ")." << std::endl;
    std::cerr << "[SYSTEM] Iniciando protocolo de graceful shutdown..." << std::endl;

    // Gravação de log emergencial garantindo fechamento de recursos
    std::ofstream logEmergencia("emergency_shutdown.log", std::ios::app);
    if (logEmergencia.is_open()) {
        logEmergencia << "Desligamento forcado via sinal " << sinal << ". Arquivos pendentes encerrados.\n";
        logEmergencia.flush();
        logEmergencia.close();
    }

    std::cerr << "[SYSTEM] Flush dos buffers concluido. Fechando o subsistema." << std::endl;
    std::exit(sinal);
}