#include "SinalHandler.h"

#include <cstdlib>
#include <iostream>

std::function<void()> SinalHandler::callback = nullptr;

void SinalHandler::registrarSalvar(const std::function<void()>& callbackSalvar) {
    callback = callbackSalvar;
}

void SinalHandler::inicializar() {
    std::signal(SIGINT, SinalHandler::tratador);
    std::signal(SIGSEGV, SinalHandler::tratador);
    std::signal(SIGTERM, SinalHandler::tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cerr << "\nSinal capturado: " << sinal << "\n";
    if (callback) {
        try {
            callback();
            std::cerr << "Dados salvos antes do encerramento.\n";
        } catch (...) {
            std::cerr << "Falha ao salvar dados durante o encerramento.\n";
        }
    }
    std::_Exit(EXIT_FAILURE);
}
