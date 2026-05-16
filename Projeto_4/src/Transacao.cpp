#include "Transacao.h"
#include "ContaBancaria.h"

Transacao::Transacao(double valor, string data) {
    this->valor = valor;
    this->data = data;
}

bool validarTransacao(ContaBancaria &conta, Transacao &transacao) {
    cout << "\n=== AUDITORIA DE TRANSACAO ===" << endl;

    cout << "Valor da transacao: R$ " << transacao.valor << endl;
    cout << "Saldo disponivel: R$ " << conta.saldo << endl;

    if (transacao.valor <= conta.saldo) {
        cout << "Transacao aprovada!" << endl;
        return true;
    }

    cout << "Transacao recusada por saldo insuficiente!" << endl;
    return false;
}