#ifndef Conta_Bancaria
#define Conta_Bancaria
#include <iostream>
#include <string>

class Transacao;

/**
 * @class contaBancaria
 * @brief Representa uma conta bancária padrão.
 * * Esta classe administra os dados de um cliente, incluindo titular, CPF e saldo.
 * O saldo é protected para permitir que função amiga
 *  possa acessá-la e manipulá-la.
 */

class contaBancaria {
    private:
        
        std::string titular;
        std::string cpf;

    protected:
        double saldo;

    public:

        /**
        * @brief Construtor da Conta Bancária.
        */
        
        contaBancaria();
         
        /**
        * @brief Destrutor da Conta Bancária.
        */
        ~contaBancaria();

        /**
        * @brief Define o nome do titular da conta.
        * @param nome String contendo o nome do titular.
        */
        void setTitular(std::string nome);

        /**
        * @brief Define o CPF do titular da conta.
        * @param cpf String contendo o CPF.
        */
        void setCPF(std::string cpf);

        /**
        * @brief Define o saldo inicial da conta.
        * @param saldo Deve ser um valor numérico maior que zero.
        */
        void setSaldo(double saldo);

        /**
        * @brief Retorna o nome do titular da conta.
        * @return std::string com o nome do titular.
        */
        std::string getTitular();

        /**
        * @brief Retorna o CPF do titular da conta.
        * @return std::string com o CPF do titular.
        */
        std::string getCPF();

        /**
        * @brief Retorna o saldo atual da conta.
        * @return double representando o saldo.
        */
        double getSaldo();

        // A declaração friend precisa existir aqui também para que o compilador a reconheça
        friend void validarTransacao(Transacao &t, contaBancaria &c);
};
#endif