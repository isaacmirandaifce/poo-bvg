#ifndef transcacao
#define transcacao
#include <iostream>
#include <string>

/**
 * @brief Classe que representa uma transação financeira no sistema.
 */
class Transacao {
    private:
        int id;
        double valor;
        std::string tipo;

    public:
        /**
         * @brief Define o ID da transação.
         * * @param id Identificador numérico (deve ser maior que zero).
         */
        void setID(int id);

        /**
         * @brief Define o valor da transação.
         * * @param valor Valor monetário da transação (deve ser maior ou igual a zero).
         */
        void setValor(double valor);
        
        /**
         * @brief Define o tipo ou modalidade da transação.
         * * @param tipo String representando a modalidade (ex: "PIX", "TED").
         */
        void setTipo(std::string tipo);

        /**
         * @brief Obtém o identificador da transação.
         * @return int O ID da transação.
         */
        int getID() const;

        /**
         * @brief Obtém o valor da transação.
         * @return double O valor da transação.
         */
        double getValor() const;

        /**
         * @brief Obtém o tipo da transação.
         * @return std::string O tipo da transação.
         */
        std::string getTipo() const;
};

#endif