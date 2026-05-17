#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"


bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
   
    if (transacao.valor <= conta.saldo) {
        return true;  
    } else {
        return false; 
    }
}


int main(){
    ContaBancaria conta1("Fernando", "123.456.789-10", 500.00);

    Transacao t1(150.00, "17/05/2026"); 
    Transacao t2(600.00, "17/05/2026");
    

    std::cout << "Tentando transação de R$ 150.00..." << std::endl;
    if (validarTransacao(conta1, t1)) {
        std::cout << "-> Transação autorizada com sucesso!\n" << std::endl;
    } else {
        std::cout << "-> Transação recusada: Saldo insuficiente!\n" << std::endl;
    }

    std::cout << "Tentando transação de R$ 600.00..." << std::endl;
    if (validarTransacao(conta1, t2)) {
        std::cout << "-> Transação autorizada com sucesso!\n" << std::endl;
    } else {
        std::cout << "-> Transação recusada: Saldo insuficiente!\n" << std::endl;
    }
    
    conta1.exibirDados();
}