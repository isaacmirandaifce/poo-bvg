#include "Transacao.h"
#include "ContaBancaria.h"

using namespace std;

// Construtor parametrizado
Transacao::Transacao(double valor, string data) {
    this->valor = valor;
    this->data = data;
}

// Funcao amiga (nao e membro de nenhuma classe): faz a auditoria comparando
// o valor da transacao com o saldo da conta, acessando ambos os atributos
// diretamente por ter sido declarada friend nas duas classes.
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    if (transacao.valor <= 0) {
        cout << "AUDITORIA: Transacao invalida (valor menor ou igual a zero)." << endl;
        return false;
    }

    if (transacao.valor > conta.saldo) {
        cout << "AUDITORIA: Transacao rejeitada. Valor (R$ " << transacao.valor
             << ") excede o saldo disponivel (R$ " << conta.saldo << ")." << endl;
        return false;
    }

    cout << "AUDITORIA: Transacao de R$ " << transacao.valor
         << " aprovada em " << transacao.data << "." << endl;
    return true;
}
