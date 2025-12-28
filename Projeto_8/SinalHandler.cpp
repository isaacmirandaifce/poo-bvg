#include "SinalHandler.h"
#include <iostream>
#include <cstdlib>

int SinalHandler::ultimoSinal = 0;

void SinalHandler::inicializar() {
    signal(SIGINT, tratador);
    signal(SIGSEGV, tratador);
    signal(SIGTERM, tratador);
}

void SinalHandler::tratador(int sinal) {
    ultimoSinal = sinal;
    std::cout << "\nEncerramento por sinal: " << sinal << std::endl;
    exit(1);
}

bool SinalHandler::sinalRecebido() {
    return ultimoSinal != 0;
}

int SinalHandler::getSinal() {
    return ultimoSinal;
}
