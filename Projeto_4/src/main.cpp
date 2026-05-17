#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

int main() {
    ContaBancaria minhaConta("João Lucas", "123,456,789-00", 1500.00);

    std::cout << "\tDados Inicias da Conta\n";
    minhaConta.exibirDados();
    std::cout << "------------------------\n\n";

// TRANSAÇÃO VÁLIDA
    std::cout << "Tentativa 1: Comprar uma passagem...\n";
    Transacao t1(450.00, "21/09/2013");
    validarTransacao(minhaConta, t1);

    std::cout << "\n";

// TRANSAÇÃO INVÁLIDA
    std::cout << "Tentativa 2: Comprar um notebook...\n";
    Transacao t2(2000.00, "21/09/2013");
    validarTransacao(minhaConta, t2);

    return 0;
}