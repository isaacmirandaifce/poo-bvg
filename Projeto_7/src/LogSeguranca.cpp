#include "LogSeguranca.h"
#include <sstream>

LogSeguranca::LogSeguranca(const std::string& timestamp, const std::string& nivel,
                            const std::string& mensagem)
    : timestamp(timestamp), nivel(nivel), mensagem(mensagem) {}

std::string LogSeguranca::getTimestamp() const {
    return timestamp;
}

std::string LogSeguranca::getNivel() const {
    return nivel;
}

std::string LogSeguranca::getMensagem() const {
    return mensagem;
}

std::string LogSeguranca::toString() const {
    std::ostringstream oss;
    oss << "[" << timestamp << "] (" << nivel << ") " << mensagem;
    return oss.str();
}
