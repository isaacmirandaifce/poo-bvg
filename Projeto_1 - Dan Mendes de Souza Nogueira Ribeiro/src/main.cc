#include <iostream>
#include <string>

// criando a classe cliente, onde as informações dos clientes ficaram privadas

class clientes
{
private:
    std::string nome_cliente;
    int idade_cliente;
    double saldo_cliente;
    bool status_ativo;

public:
    // Definido os "set" para podemos alterar os dados privados fora da classe

    void setNome(std::string nome) { nome_cliente = nome; };
    void setIdade(int idade) { idade_cliente = idade; };
    void setSaldo(double saldo) { saldo_cliente = saldo; };
    void setStatus(bool status) { status_ativo = status; };

    // Definido os "get" para podermos acessar informações privadas fora da classe
    std::string getNome() { return nome_cliente; };
    int getIdade() { return idade_cliente; };
    double getSaldo() { return saldo_cliente; };
    bool getStatus() { return status_ativo; };

    // Definido a operação de saque da conta

    double saqueConta(double valor) { return saldo_cliente -= valor; };
    double depositoConta(double valor) { return saldo_cliente += valor; };
};

// Criando a classe Banco

class Banco
{
private:
    clientes lista_Clientes[100];
    int total_clientes = 0;

public:
    // A função de cadastrar clientes

    void cadastrar_cliente(std::string nome, int idade, double saldo_inicial)
    {

        if (total_clientes < 100)
        {
            lista_Clientes[total_clientes].setNome(nome);
            lista_Clientes[total_clientes].setIdade(idade);
            lista_Clientes[total_clientes].setSaldo(saldo_inicial);
            lista_Clientes[total_clientes].setStatus(true);
            total_clientes++;

            std::cout << "Sucesso: Cliente " << nome << " cadastrado com ID " << total_clientes - 1 << std::endl;
        }
        else
        {
            std::cout << "Erro Crítico: Limite de memória atingido." << std::endl;
        }
    }

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

                        std::cout << "Saque de R$" << valor << " realizado. Novo saldo: R$" << lista_Clientes[id_cliente].getSaldo() << '\n';
                    }
                    else
                    {
                        std::cout << "Saldo insuficiente para saque." << std::endl;
                    };
                }
                else
                {
                    lista_Clientes[id_cliente].depositoConta(valor);

                    std::cout << "Saque de R$" << valor << " realizado. Novo saldo: R$" << lista_Clientes[id_cliente].getSaldo() << '\n';
                }
            }
            else
            {
                std::cout << "Erro: Conta inativa.";
            }
        }
        else
        {
            std::cout << "Erro: Cliente não encontrado no sistema.";
        }
    }

    void exibir_relatorio(){
    std::cout << std::endl << "--- RELATÓRIO GERAL ---" << std::endl;

    for(int i = 0; i < total_clientes; i++ ){
        std::cout << std::endl << "ID " << i << " Nome: " << lista_Clientes[i].getNome() << " Saldo:" << lista_Clientes[i].getSaldo() << " Ativo: " << (lista_Clientes[i].getStatus() ? "Sim" : "Não") << std::endl;
    }
}

};

int main(){ 

// Simulando o uso do sistema

    Banco rodarBanco;

   rodarBanco.cadastrar_cliente("João Silva", 30, 1000.0);
   rodarBanco.cadastrar_cliente("Maria Souza", 25, 500.0);

// A Operação perigosa.
    rodarBanco.movimentar_conta(0, 1500.0, true); // No sistema atual ela vai ser previnida.
    
    rodarBanco.exibir_relatorio();

    return 0;

}