#ifndef LOGSEGURANCA_H
#define LOGSEGURANCA_H

#include <string>

/**
 * @class LogSeguranca
 * @brief Representa um registro de log de segurança do sistema.
 *
 * Segunda classe de domínio utilizada para provar que DataFilter<T> é
 * agnóstico ao tipo armazenado. Possui um timestamp, um nível de
 * severidade (ex.: "INFO", "CRITICAL") e uma mensagem descritiva.
 */
class LogSeguranca {
private:
    std::string timestamp;
    std::string nivel;
    std::string mensagem;

public:
    LogSeguranca(const std::string& timestamp, const std::string& nivel,
                 const std::string& mensagem);

    std::string getTimestamp() const;
    std::string getNivel() const;
    std::string getMensagem() const;

    /**
     * @brief Gera uma representação textual do log, usada pelo método
     * processar() de DataFilter<LogSeguranca> para impressão em log.
     */
    std::string toString() const;
};

#endif // LOGSEGURANCA_H
