#ifndef LOGSEGURANCA_H
#define LOGSEGURANCA_H

#include <string>

class LogSeguranca {
public:
    int timestamp;
    std::string nivel;
    std::string mensagem;

    LogSeguranca(int timestamp, std::string nivel, std::string mensagem);
    void exibir() const;
};

#endif