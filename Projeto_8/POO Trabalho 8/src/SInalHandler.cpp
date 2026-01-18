#include "SinalHandler.h"
#include <iostream>

SinalHandler::Handler SinalHandler::shutdownHandler = nullptr;

void SinalHandler::inicializar() {
    std::signal(SIGINT, SinalHandler::tratador);
    std::signal(SIGTERM, SinalHandler::tratador);
    std::signal(SIGSEGV, SinalHandler::tratador);
}

void SinalHandler::setShutdownHandler(Handler h) {
    shutdownHandler = h;
}

void SinalHandler::tratador(int sinal) {
    switch (sinal) {
        case SIGINT:
            std::cerr << "Recebido SIGINT (Ctrl+C). Tentando salvar dados...\n";
            break;
        case SIGTERM:
            std::cerr << "Recebido SIGTERM. Tentando salvar dados...\n";
            break;
        case SIGSEGV:
            std::cerr << "Recebido SIGSEGV (falha de segmentação). Tentando salvar dados com segurança...\n";
            break;
        default:
            std::cerr << "Recebido sinal " << sinal << ". Tentando salvar dados...\n";
    }

    if (shutdownHandler) {
        try {
            shutdownHandler();
        } catch (...) {
            std::cerr << "Erro ao executar rotina de salvamento no tratador de sinais.\n";
        }
    }

    std::_Exit(1);
}
