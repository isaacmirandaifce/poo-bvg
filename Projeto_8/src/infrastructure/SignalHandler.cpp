#include "SignalHandler.h"
#include <cstdlib>
#include <fstream>

void SignalHandler::inicializar() {
    std::signal(SIGINT, SignalHandler::tratador);
    std::signal(SIGTERM, SignalHandler::tratador);
}

void SignalHandler::tratador(int sinal) {
    std::cerr << "\n(Critical Alert) Sinal de interrupção recebido do SO (Signal ID: " << sinal << ").\n";

    std::ofstream log("emergency_shutdown.log", std::ios::app);
    if (log.is_open()) {
        log << "SISTEMA TERMINADO ABRUPTAMENTE. Sinal capturado: " << sinal << "\n";
        log.close();
    }

    std::cerr << "(ENGINE) Estado Emergencial salvo. Arquivos pendentes fechados. encerrando de forma segura\n";
    std::exit(sinal);
}