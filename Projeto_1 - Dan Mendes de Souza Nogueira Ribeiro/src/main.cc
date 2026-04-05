/**
* @file RefatoraçãoCódigoBancario.cpp
* @brief Refatoração de Código Estruturado para Programação Orientada a Objetos.
* Este arquivo contém a Refatoração de um código legacy em python para agora em c++, além disso, ajuste foram feitos no código para corrigir BUGS da versão legacy
 */

#include <iostream>
#include <string>

// criando a classe cliente.

/**
 * @class clientes
 * @brief Classe que representa um cliente do banco.
 * * Gerencia as informações pessoais e o estado financeiro de um cliente individual.
 * Fornece métodos de acesso (getters e setters) e operações diretas no saldo.
 */
class clientes
{
private:

    //Definimos os dados do cliente de forma privada.
    std::string nome_cliente;
    int idade_cliente;
    double saldo_cliente;
    bool status_ativo;

public:
    
    // Definido os setters para podemos alterar os dados privados fora da classe.

    /**
     * @brief Define o nome do cliente.
     * @param nome String contendo o nome do cliente.
     */
    void setNome(std::string nome) { nome_cliente = nome; };
    
    /**
     * @brief Define a idade do cliente.
     * @param idade Inteiro representando a idade do cliente.
     */
    void setIdade(int idade) { idade_cliente = idade; };

    /**
     * @brief Define o saldo atual da conta do cliente.
     * @param saldo Valor de ponto flutuante representando o saldo.
     */
    void setSaldo(double saldo) { saldo_cliente = saldo; };

    /**
     * @brief Define o status da conta do cliente.
     * @param status Booleano onde true = ativo e false = inativo.
     */
    void setStatus(bool status) { status_ativo = status; };

    // Definido os getters para podermos acessar informações privadas fora da classe.

    /**
     * @brief Retorna o nome do cliente.
     * @return std::string Nome do cliente.
     */
    std::string getNome() { return nome_cliente; };

    /**
     * @brief Retorna a idade do cliente.
     * @return int Idade do cliente.
     */
    int getIdade() { return idade_cliente; };

    /**
     * @brief Retorna o saldo da conta do cliente.
     * @return double Valor atual do saldo.
     */
    double getSaldo() { return saldo_cliente; };

    /**
     * @brief Retorna o status de atividade da conta.
     * @return true se a conta estiver ativa, false caso contrário.
     */
    bool getStatus() { return status_ativo; };

    // Definido a operação de saque e deposito das contas.

    /**
     * @brief Realiza um saque na conta do cliente (sem validação interna).
     * @param valor Valor a ser subtraído do saldo.
     * @return double Novo saldo após a operação.
     */
    double saqueConta(double valor) { return saldo_cliente -= valor; };

    /**
     * @brief Realiza um depósito na conta do cliente.
     * @param valor Valor a ser adicionado ao saldo.
     * @return double Novo saldo após a operação.
     */
    double depositoConta(double valor) { return saldo_cliente += valor; };
};

// Criando a classe Banco.

/**
 * @class Banco
 * @brief Classe que gerencia o sistema do banco e a lista de clientes.
 * * Permite cadastrar até 100 clientes, movimentar contas (com validação
 * de segurança para evitar saldos negativos) e emitir relatórios.
 */
class Banco
{
private:

    // Definimos os dados do Banco de forma privada.

    clientes lista_Clientes[100];
    int total_clientes = 0;

public:
    // A função de cadastrar clientes.

    /**
     * @brief Cadastra um novo cliente no sistema do banco.
     * * Verifica se há espaço no vetor de clientes. Em caso positivo,
     * inicializa os dados do cliente e o define como ativo.
     * * @param nome Nome do novo cliente.
     * @param idade Idade do novo cliente.
     * @param saldo_inicial Saldo inicial da conta.
     */

    void cadastrar_cliente(std::string nome, int idade, double saldo_inicial)
    {

        if (total_clientes < 100)
        {
            lista_Clientes[total_clientes].setNome(nome);
            lista_Clientes[total_clientes].setIdade(idade);
            lista_Clientes[total_clientes].setSaldo(saldo_inicial);
            lista_Clientes[total_clientes].setStatus(true);
            total_clientes++;

            std::cout << std::endl << "Sucesso: Cliente " << nome << " cadastrado com ID " << total_clientes - 1 << std::endl;
        }
        else
        {
            std::cout << std::endl << "Erro Crítico: Limite de memória atingido." << std::endl;
        }
    }

    // A função de movimentar o saldo das contas. No código legacy, tem um BUG envolvendo o saque, ele foi corrigido nesse codigo.

    /**
     * @brief Realiza uma movimentação (saque ou depósito) na conta de um cliente.
     * * Valida se o ID do cliente existe, se a conta está ativa e, em caso de saque,
     * impede a operação se o cliente não tiver saldo suficiente, prevenindo o BUG
     * de saldo negativo do sistema legado.
     * * @param id_cliente O ID gerado no momento do cadastro do cliente.
     * @param valor O montante financeiro da operação.
     * @param is_saque Se true, realiza um saque; se false, realiza um depósito.
     */

    void movimentar_conta(int id_cliente, double valor, bool is_saque)
    {

        if (0 <= id_cliente && id_cliente < total_clientes)
        {

            if (lista_Clientes[id_cliente].getStatus())
            {

                if (is_saque)
                {
                    // corrigindo o BUG do saldo negativo botando uma validação para valores negativos.

                    double saldo_teste = lista_Clientes[id_cliente].getSaldo() - valor;

                    if (saldo_teste >= 0)
                    {

                        lista_Clientes[id_cliente].saqueConta(valor);

                        std::cout << std::endl << "Saque de R$" << valor << " realizado. Novo saldo: R$" << lista_Clientes[id_cliente].getSaldo() << std::endl;
                    }
                    else
                    {
                        //Caso o valor for negativo ira aparecer essa mensagem para o cliente.
                        std::cout << std::endl << "Saldo insuficiente para saque." << std::endl;
                    };
                }
                else
                {
                    lista_Clientes[id_cliente].depositoConta(valor);

                    std::cout << std::endl << "Saque de R$" << valor << " realizado. Novo saldo: R$" << lista_Clientes[id_cliente].getSaldo() << std::endl;
                }
            }
            else
            {
                std::cout << std::endl << "Erro: Conta inativa.";
            }
        }
        else
        {
            std::cout << std::endl << "Erro: Cliente não encontrado no sistema.";
        }
    }

    /**
     * @brief Exibe o relatório de todos os clientes cadastrados.
     * * Imprime no terminal o ID, Nome, Saldo e Status (Ativo ou Inativo)
     * de todos os clientes atualmente registrados no banco.
     */

    void exibir_relatorio(){
    std::cout << std::endl << "--- RELATÓRIO GERAL ---" << std::endl;

    for(int i = 0; i < total_clientes; i++ ){
        std::cout << std::endl << "ID " << i << " Nome: " << lista_Clientes[i].getNome() << " Saldo:" << lista_Clientes[i].getSaldo() << " Ativo: " << (lista_Clientes[i].getStatus() ? "Sim" : "Não") << std::endl;
    }
}

};

/**
 * @brief Função principal responsável por simular a execução do sistema bancário.
 * @return int Retorna 0 em caso de execução bem-sucedida.
 */

int main(){ 

// Simulando o uso do sistema

    // Instanciação do sistema do Banco
    Banco rodarBanco;

    // Cadastro de usuários
   rodarBanco.cadastrar_cliente("João Silva", 30, 1000.0);
   rodarBanco.cadastrar_cliente("Maria Souza", 25, 500.0);

// A Operação perigosa.
    rodarBanco.movimentar_conta(0, 1500.0, true); // No sistema atual ela vai ser previnida.
    
    // Geração do relatório final
    rodarBanco.exibir_relatorio();

    return 0;

}