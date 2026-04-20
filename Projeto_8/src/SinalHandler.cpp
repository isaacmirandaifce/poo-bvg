#include "SinalHandler.h"

void SinalHandler::inicializar() {
    signal(SIGINT, tratador);
    signal(SIGTERM, tratador);
    signal(SIGSEGV, tratador);
}

void SinalHandler::tratador (int sinal) {
    if (sinal == SIGINT) {
        std::cout << "\nPrograma interrompido (Ctrl+C)\n";
    }

    if (sinal == SIGTERM) {
        std::cout << "\nPrograma finalizado pelo sistema\n";
    }

    if (sinal == SIGSEGV) {
        std::cout << "\nErro grave de memória (Segmentation Fault)\n";
    }

    std::cout << "Encerrando sistema com segurança...\n";

    exit(1);
}