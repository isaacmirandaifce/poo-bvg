#include <iostream>
#include "../src/Pessoa.h" 

using namespace std;

void testarConstrutorPadrao() {
    cout << "== Teste Construtor Padrão ==" << endl;
    Pessoa pessoa1;
    pessoa1.imprimirNome();
    pessoa1.imprimirTelefone();
    cout << endl;
}

void testarConstrutorParametrizado() {
    cout << "== Teste Construtor Parametrizado ==" << endl;
    Pessoa pessoa2("Maria", "1234-5678");
    pessoa2.imprimirNome();
    pessoa2.imprimirTelefone();
    cout << endl;
}

void testarDestrutor() {
    cout << "== Teste Destrutor ==" << endl;
    {
        Pessoa pessoa3("Lucas", "8765-4321");
        pessoa3.imprimirNome();
    } 
    cout << endl;
}

int main() {
    testarConstrutorPadrao();
    testarConstrutorParametrizado();
    testarDestrutor();

    return 0;
}
