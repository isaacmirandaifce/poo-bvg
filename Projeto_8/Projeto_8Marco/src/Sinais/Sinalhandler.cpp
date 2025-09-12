#include "SinalHandler.h"

std::function<void()> SinalHandler::callbackDeSaida = nullptr;

void SinalHandler::inicializar() {
    std::signal(SIGINT, tratador);   // Ctrl+C
    std::signal(SIGTERM, tratador);  // kill
    std::signal(SIGSEGV, tratador);  // falha de segmentação
}

void SinalHandler::definirCallbackDeSaida(std::function<void()> callback) {
    callbackDeSaida = callback;
}

void SinalHandler::tratador(int sinal) {
    std::cerr << "\n[SINAL CAPTURADO] ";

    switch (sinal) {
        case SIGINT:
            std::cerr << "Encerramento via Ctrl+C (SIGINT)." << std::endl;
            break;
        case SIGTERM:
            std::cerr << "Finalização solicitada pelo sistema (SIGTERM)." << std::endl;
            break;
        case SIGSEGV:
            std::cerr << "Acesso inválido à memória (SIGSEGV)." << std::endl;
            break;
        default:
            std::cerr << "Sinal desconhecido: " << sinal << std::endl;
            break;
    }

    if (callbackDeSaida) {
        std::cerr << "Salvando dados antes de encerrar..." << std::endl;
        callbackDeSaida();
    }

    std::exit(1);
}