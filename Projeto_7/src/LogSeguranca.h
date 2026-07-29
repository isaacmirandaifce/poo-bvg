#ifndef LOG_SEGURANCA_H
#define LOG_SEGURANCA_H

#include <string>

class LogSeguranca {
private:
    std::string timestamp;
    std::string nivel; // Ex: "INFO", "CRITICAL"
    std::string mensagem;

public:
    LogSeguranca(std::string timestamp, std::string nivel, std::string mensagem);

    std::string getTimestamp() const;
    std::string getNivel() const;
    std::string getMensagem() const;

    void exibir() const;
};

#endif // LOG_SEGURANCA_H