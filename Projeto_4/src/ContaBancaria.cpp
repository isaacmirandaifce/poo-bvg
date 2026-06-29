#include "ContaBancaria.h"
#include "Transacao.h"
#include <iostream>

// Constructor da classe ContaBancaria...
ContaBancaria::ContaBancaria(std::string t, std::string c, double s) : titular(t), cpf(c), saldo(s) {}

// Método para imprimir dados da conta na tela
void ContaBancaria::exibirDados() const {
    std::cout << "Titular: " << titular << "\n" << "CPF: " << cpf << "\n" << "Saldo Atual: R$ " << saldo << "\n";
}

// Função global independente
// Graças à amizade, a função acessa diretamente 'transacao.valor' (que é privado)
// e 'conta.saldo' (que é protegido), sem precisar de métodos Getters.
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    if (transacao.valor > conta.saldo) {
        std::cout << "[ALERTA] Transação recusada Valor (R$ " << transacao.valor << ") maior que o saldo (R$ " << conta.saldo << ").\n";
        return false;
    }

    std::cout << "[SUCESSO] Transação de R$ " << transacao.valor << " autorizada para processamento.\n";
    return true;
}