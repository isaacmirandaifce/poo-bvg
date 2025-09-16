#include "SinalHandler.h"
#include <iostream>
#include <cstdlib>

std::atomic<bool> SinalHandler::ativo{false};
std::function<void(int)> SinalHandler::callbackSeguro = nullptr;

void SinalHandler::tratador(int sinal) {
    std::cerr << "\n[SINAL] Capturado sinal " << sinal << ".\n";
    if (callbackSeguro) {
        try { callbackSeguro(sinal); } catch(...) {}
    }
    ativo.store(false);
}

void SinalHandler::inicializar() {
    ativo.store(true);
    std::signal(SIGINT,  SinalHandler::tratador);
    std::signal(SIGTERM, SinalHandler::tratador);
#ifdef SIGSEGV
    std::signal(SIGSEGV, SinalHandler::tratador);
#endif
}

void SinalHandler::registrarCallbackSeguro(std::function<void(int)> cb) {
    callbackSeguro = std::move(cb);
}

bool SinalHandler::estaAtivo() {
    return ativo.load();
}
