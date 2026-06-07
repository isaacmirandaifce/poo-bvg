#include "LogSeguranca.h"
#include <iostream>

LogSeguranca::LogSeguranca(int timestamp, std::string nivel, std::string mensagem)
    : timestamp(timestamp), nivel(nivel), mensagem(mensagem) {}

void LogSeguranca::exibir() const {
    std::cout << "[LOG] Timestamp: " << timestamp
              << " | Nivel: " << nivel
              << " | Mensagem: " << mensagem << std::endl;
}