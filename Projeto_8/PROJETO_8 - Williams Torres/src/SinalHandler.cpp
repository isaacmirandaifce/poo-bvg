#include "SinalHandler.h"

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);
    std::signal(SIGTERM, tratador);
    std::signal(SIGSEGV, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cout << "Sinal capturado: " << sinal << "\nSalvando dados e encerrando a aplicacao com seguranca." << std::endl;
    exit(1);
}