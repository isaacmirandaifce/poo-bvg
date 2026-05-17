#ifndef Trans_h
#define Trans_h
#include<iostream>
#include <string>

class contaBancaria;

/**
 * @class Transacao
 * @brief Representa um pedido de transação financeira.
 * * Esta classe armazena o valor da transação e o cpf de quem 
 * a solicitou.
 */
class Transacao{
    private:
        double valor;
        std::string cpf;

    public:

        /**
        * @brief Construtor da Transação.
        */
        Transacao();

        /**
         * @brief Destrutor da Transação.
         */
        ~Transacao();

        /**
         * @brief Define o valor da transação.
         * @param valor Deve ser um valor numérico maior que zero.
         */
        void setValor(double valor);

        /**
         * @brief Define o CPF de quem solicitou.
         * @param data String contendo o CPF.
         */
        void setCPF(std::string cpf);

        /**
         * @brief Retorna o CPF.
         * @return std::string com o CPF.
         */
        std::string getCPF();

        /**
         * @brief Retorna o valor da transação.
         * @return double representando o valor.
         */
        double getValor();
        
        /**
         * @brief Função amiga para validar e processar uma transação.
         * * Avalia se a transação solicitada tem um valor válido e se há
         * saldo suficiente na conta bancária para realizá-la.
         * * @param t Referência para o objeto Transacao.
         * @param c Referência para o objeto contaBancaria.
         */
        friend void validarTransacao(Transacao &t, contaBancaria &c);
};

#endif