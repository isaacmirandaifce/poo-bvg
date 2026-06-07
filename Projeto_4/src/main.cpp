#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

using namespace std;

int main() {
    cout << "======================================" << endl;
    cout << "   Sistema Bancario  Modulo Auditoria" << endl;
    cout << "======================================" << endl;

    // Criando a conta do cliente
    ContaBancaria conta("Ana Paula Souza", "123.456.789-00", 1500.00);

    cout << "\n[ Dados da Conta ]" << endl;
    conta.exibirDados();

    // Teste 1: transacao dentro do saldo
    cout << "\n[ Tentativa de Transacao #1 ]" << endl;
    Transacao t1(800.00, "17/05/2026");
    t1.exibirTransacao();
    validarTransacao(conta, t1);

    // Teste 2: transacao acima do saldo
    cout << "\n[ Tentativa de Transacao #2 ]" << endl;
    Transacao t2(2000.00, "17/05/2026");
    t2.exibirTransacao();
    validarTransacao(conta, t2);

    // Teste 3: valor invalido
    cout << "\n[ Tentativa de Transacao #3 ]" << endl;
    Transacao t3(-50.00, "17/05/2026");
    t3.exibirTransacao();
    validarTransacao(conta, t3);

    cout << "\n======================================" << endl;

    return 0;
}