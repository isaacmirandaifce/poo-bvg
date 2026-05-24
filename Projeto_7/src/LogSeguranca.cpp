#include "LogSeguranca.h"

LogSeguranca::LogSeguranca(std::string timestamp,
                           std::string nivel,
                           std::string mensagem) {
    this->timestamp = timestamp;
    this->nivel = nivel;
    this->mensagem = mensagem;
}

std::string LogSeguranca::getTimestamp() const {
    return timestamp;
}

std::string LogSeguranca::getNivel() const {
    return nivel;
}

std::string LogSeguranca::getMensagem() const {
    return mensagem;
}