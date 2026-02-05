#include "SinalHandler.h"
#include <csignal>
#include <iostream>
#include <cstdlib>

void SinalHandler::inicializar() {
    signal(SIGINT, tratador);
    signal(SIGTERM, tratador);
    signal(SIGSEGV, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cout << "\nEncerrando aplicação. Sinal recebido: "
              << sinal << std::endl;
    std::exit(1);
}