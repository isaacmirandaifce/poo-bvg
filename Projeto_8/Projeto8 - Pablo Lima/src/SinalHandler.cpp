#include "SinalHandler.h"

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);
    std::signal(SIGTERM, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\nSinal " << sinal << " capturado. Salvando dados antes de sair..." << std::endl;
    exit(1);
}