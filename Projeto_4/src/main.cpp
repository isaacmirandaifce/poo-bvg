#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

using namespace std;

int main() {
    // Criando a conta bancaria do cliente
    ContaBancaria conta("Davi Maciel", "123.456.789-00", 1500.00);

    cout << "===== Modulo de Auditoria de Transacoes Bancarias =====" << endl;
    conta.exibirDadosBasicos();
    cout << endl;

    // Tentativa de transacao dentro do limite do saldo
    Transacao transacaoValida(500.00, "17/06/2026");
    cout << "--- Tentativa de transacao 1 ---" << endl;
    validarTransacao(conta, transacaoValida);
    cout << endl;

    // Tentativa de transacao acima do saldo disponivel
    Transacao transacaoInvalida(5000.00, "17/06/2026");
    cout << "--- Tentativa de transacao 2 ---" << endl;
    validarTransacao(conta, transacaoInvalida);

    return 0;
}
