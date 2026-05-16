#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

using namespace std;

int main() {

    ContaBancaria conta1("Gabriel Uaren", "123.456.789-00", 1500.00);

    Transacao transacao1(1000.00, "11/05/2026");

    conta1.exibirDados();

    validarTransacao(conta1, transacao1);

    return 0;
}