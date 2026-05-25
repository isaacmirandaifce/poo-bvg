#ifndef Log_Seguranca
#define Log_Seguranca
#include <iostream>
#include <string>

/**
 * @brief Classe que representa um registro de log de segurança do sistema.
 */
class LogSeguranca
{
private:
    int timestamp;
    std::string nivel;
    std::string mensagem;

public:
    /**
     * @brief Define a marca de tempo (timestamp) do log.
     * * @param timestamp Valor numérico representando o tempo (deve ser maior ou igual a zero).
     */
    void setTimeStamp(int timestamp);

    /**
     * @brief Define o nível de criticidade do log.
     * * @param nivel String com o nível do log (ex: "INFO", "CRITICAL").
     */
    void setNivel(std::string nivel);

    /**
     * @brief Define a mensagem descritiva do log de segurança.
     * * @param mensagem Texto detalhando o evento ocorrido.
     */
    void setMensagem(std::string mensagem);

    /**
     * @brief Obtém a marca de tempo do log.
     * @return int O timestamp registrado.
     */
    int getTimeStamp() const;

    /**
     * @brief Obtém o nível de criticidade do log.
     * @return std::string O nível do log.
     */
    std::string getNivel() const;

    /**
     * @brief Obtém a mensagem do log.
     * @return std::string A mensagem registrada.
     */
    std::string getMensagem() const;
};

#endif