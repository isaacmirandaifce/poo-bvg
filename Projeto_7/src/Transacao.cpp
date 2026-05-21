#include "Transacao.h"

void exibirTransacao(Transacao t) {
    cout << "ID: " << t.id
         << " | Valor: R$" << t.valor
         << " | Tipo: " << t.tipo << endl;
}