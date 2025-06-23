#include <iostream>
#include <vector>
#include "src/Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> listaPessoas;

    // Adicionando objetos ao vetor
    listaPessoas.push_back(Pessoa("Rafael Costa", "85 91234-5678"));
    listaPessoas.push_back(Pessoa("João Silva", "85 99876-5432"));
    listaPessoas.push_back(Pessoa("Maria Oliveira", "85 98765-4321"));

    // Exibindo informações
    for (const Pessoa& p : listaPessoas) {
        p.imprimirDados();
    }

    return 0;
}
