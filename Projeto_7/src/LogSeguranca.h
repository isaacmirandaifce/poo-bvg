#ifndef LOGSEGURANCA_H
#define LOGSEGURANCA_H

#include <iostream>
#include <string>
using namespace std;

struct LogSeguranca {
    string timestamp;
    string nivel;
    string mensagem;
};

void exibirLog(LogSeguranca log);

#endif