#ifndef LOGSEGURANCA_H
#define LOGSEGURANCA_H

#include <string>

// Classe de dominio 2: representa um registro de log de seguranca do SecureBank Pro.
class LogSeguranca {
private:
    std::string timestamp;
    std::string nivel; // "INFO", "CRITICAL"
    std::string mensagem;

public:
    LogSeguranca();
    LogSeguranca(std::string timestamp, std::string nivel, std::string mensagem);

    std::string getTimestamp() const;
    std::string getNivel() const;
    std::string getMensagem() const;

    void exibir() const;
};

#endif // LOGSEGURANCA_H
