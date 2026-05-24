#ifndef LOGSEGURANCA_H
#define LOGSEGURANCA_H

#include <string>

class LogSeguranca {
private:
    std::string timestamp;
    std::string nivel;
    std::string mensagem;

public:
    LogSeguranca(std::string timestamp,
                 std::string nivel,
                 std::string mensagem);

    std::string getTimestamp() const;
    std::string getNivel() const;
    std::string getMensagem() const;
};

#endif