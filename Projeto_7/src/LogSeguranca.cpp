#include <iostream>
#include "LogSeguranca.h"

using namespace std;

LogSeguranca::LogSeguranca() : timestamp(""), nivel(""), mensagem("") {}

LogSeguranca::LogSeguranca(string timestamp, string nivel, string mensagem)
    : timestamp(timestamp), nivel(nivel), mensagem(mensagem) {}

string LogSeguranca::getTimestamp() const {
    return timestamp;
}

string LogSeguranca::getNivel() const {
    return nivel;
}

string LogSeguranca::getMensagem() const {
    return mensagem;
}

void LogSeguranca::exibir() const {
    cout << "[" << timestamp << "] (" << nivel << ") " << mensagem << endl;
}
