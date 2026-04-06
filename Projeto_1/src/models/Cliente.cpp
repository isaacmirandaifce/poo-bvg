#include "Cliente.h"

// Construtor: inicializa os dados do cliente

Cliente::Cliente(std::string n, int i, double s) {
    nome = n;
    idade = i;
    saldo = s;
    status = true;
}

// Saque: diminui o saldo se possível

void Cliente::saque(double valor){
    if(valor < 0){
        std::cout << "Valor invalido\n";
    }
    else if(valor > saldo){
        std::cout << "Saldo insuficiente\n";
    }
    else{
        saldo -= valor;
        std::cout << "Saque efetuado com sucesso\n";
    }
}

// Depósito: aumenta o saldo
void Cliente::deposito(double valor){
    saldo +=valor;
    std::cout << "Deposito efetuado com sucesso\n";
}

// Retorna nome
std::string Cliente::getNome() { return nome; }

// Retorna idade
int Cliente::getIdade() { return idade; }

// Retorna saldo
double Cliente::getSaldo() { return saldo; }

// Retorna status
bool Cliente::getStatus() { return status; }

// Adiciona cliente ao vetor

void cadastrar_Cliente(std::vector<Cliente>& clientes, std::string nome, int idade, double saldo) {
    if (clientes.size() < 100) {
        clientes.push_back(Cliente(nome, idade, saldo));
    }
}

// Mostra todos os clientes
void exibirRelatorio(std::vector<Cliente>& clientes) {
    std::cout << "--- Relatorio de contas ---\n";

    for (int i = 0; i < clientes.size(); i++) {
        std::cout << "ID: " << i
                  << " -- Nome: " << clientes[i].getNome()
                  << " -- Idade: " << clientes[i].getIdade()
                  << " -- Saldo: " << clientes[i].getSaldo()
                  << " -- Ativo: " << clientes[i].getStatus()
                  << "\n";
    }
}