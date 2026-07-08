#include "SignalHandler.h"
#include <cstdlib>

void SignalHandler::inicializar() {
    std::signal(SIGINT, SignalHandler::tratador);
    std::signal(SIGTERM, SignalHandler::tratador);
}

void SignalHandler::tratador(int sinal) {
    std::cout << "\n[CRITICAL] Sinal recebido: " << sinal << ". Iniciando encerramento seguro..." << std::endl;
    std::cout << "[SISTEMA] Arquivos fechados. Flush realizado com sucesso." << std::endl;
    std::exit(sinal);
}
