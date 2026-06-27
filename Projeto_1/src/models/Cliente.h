#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include <string>

/*
Classe Cliente
Representa um cliente com nome, idade, saldo e status.
*/
class Cliente{
    
private: 
    std::string nome;   // nome do cliente
    int idade;          // idade do cliente
    double saldo;       // saldo da conta
    bool status;        // status da conta (ativa/inativa)
    
public:  
    //Construtor. Recebe nome, idade e saldo inicial.

    Cliente(std::string n, int i, double s);
    
    //Realiza saque

    void saque(double valor);
    
    //Realiza depósito
    
    void deposito(double valor);

//retorna informações do cliente
    std::string getNome();

    int getIdade();

    double getSaldo();

    bool getStatus();
};

// Cadastra um cliente no vetor


void cadastrar_Cliente(std::vector<Cliente>& clientes, std::string nome, int idade, double saldo);

// Exibe relatório de todos os clientes

void exibirRelatorio(std::vector<Cliente>& clientes);

#endif