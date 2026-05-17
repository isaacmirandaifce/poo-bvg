#include <iostream>
#include <string>
#include "transacao.h"
#include "contaBancaria.h"


int main () {

    contaBancaria conta;

    conta.setTitular("Fulano");

    conta.setCPF("000.000.000-00");

    conta.setSaldo(150);


    Transacao novaTransacao;

    novaTransacao.setCPF("000.000.000-00");
    
    novaTransacao.setValor(100);

    validarTransacao(novaTransacao, conta);

    std::cout << '\n' << "o saldo da conta é: " << conta.getSaldo() << "\n";

    validarTransacao(novaTransacao, conta);

    return 0;
}