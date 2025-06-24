#include <iostream>
#include <cassert>
#include "../src/Pessoa.h"

using namespace std;

int main() {
    // teste do construtor parametrizado
    Pessoa p1("João", "1111-2222");

    // testando se os métodos imprimem corretamente
    cout << "Executando testes..." << endl;

    cout << "Esperado: Nome: João" << endl;
    p1.imprimirNome();
    cout << "Esperado: Telefone: 1111-2222" << endl;
    p1.imprimirTelefone();

    cout << "Todos os testes visuais executados." << endl;
    return 0;
}
