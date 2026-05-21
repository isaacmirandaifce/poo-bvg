#include "LogSeguranca.h"

void exibirLog(LogSeguranca log) {
    cout << "[" << log.nivel << "] "
         << log.timestamp
         << " -> " << log.mensagem << endl;
}