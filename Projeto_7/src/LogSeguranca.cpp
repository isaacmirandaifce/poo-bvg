#include "LogSeguranca.h"

LogSeguranca::LogSeguranca(std::string timestamp, std::string nivel, std::string mensagem) 
    : timestamp(timestamp), nivel(nivel), mensagem(mensagem) {}

std::string LogSeguranca::getTimestamp() const { return timestamp; }
std::string LogSeguranca::getNivel() const { return nivel; }
std::string LogSeguranca::getMensagem() const { return mensagem; }