#include "Banco.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include <iostream>
using namespace std;

Banco::~Banco() {
    for(auto conta : contas) {
        delete conta;
    }
}

void Banco::adicionarConta(Conta* conta) {
    contas.push_back(conta);
}

void Banco::listarContas() const {
    cout << "=== Contas no banco (" << contas.size() << ") ===" << endl;
    for(const auto* conta : contas){
        conta->exibir();
        cout << "----------------------" << endl;
    }
}

void Banco::realizarOperacoes() {
    if(contas.size() >= 2) {
        contas[0]->sacar(200);
        contas[1]->depositar(300);
        auto* cp = dynamic_cast<ContaPoupanca*>(contas[1]);
        if(cp) cp->render();
    }
    listarContas();
}
