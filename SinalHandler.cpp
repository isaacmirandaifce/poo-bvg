#include "SinalHandler.h"
#include <csignal>
#include <iostream>

namespace {
    std::function<void()> funcaoSaida = nullptr;
}

void handler(int sinal) {
    std::cerr << "\nRecebido sinal " << sinal << ". Saindo...\n";
    if (funcaoSaida) funcaoSaida();
    exit(sinal);
}

void SinalHandler::configurar() {
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
}

void SinalHandler::setFuncaoSaida(std::function<void()> funcao) {
    funcaoSaida = funcao;
}