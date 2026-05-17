#include <iostream>
#include <string>
#include "transacao.h"
#include "contaBancaria.h"


int main () {

    contaBancaria conta;

    conta.setTitular("Fulano");

    conta.setCPF("000.000.000-00");

    conta.setSaldo(150);

    std::cout << '\n' << "Conta ---- Titular: " << conta.getTitular() << " | CPF: " << conta.getCPF() << " | Valor escolhido: R$" << conta.getSaldo() << '\n';

    Transacao novaTransacao;

    novaTransacao.setCPF("000.000.000-00");
    
    novaTransacao.setValor(100);

    std::cout << '\n' << "Transação ---- CPF: " << novaTransacao.getCPF() << " | Saldo: R$" << novaTransacao.getValor() << '\n';

    validarTransacao(novaTransacao, conta);

    std::cout << '\n' << "o saldo atual da conta é: R$" << conta.getSaldo() << "\n";

    validarTransacao(novaTransacao, conta);

    std::cout << '\n' << "Conta ---- Titular: " << conta.getTitular() << " | CPF: " << conta.getCPF() << " | Saldo: R$" << conta.getSaldo() << '\n';

    return 0;
}