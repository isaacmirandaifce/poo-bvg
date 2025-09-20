#include <iostream>
#include <vector>    // Para usar o container std::vector
#include "Pessoa.h"

using namespace std;

int main() {
    // Criar um container std::vector para armazenar objetos do tipo Pessoa
    vector<Pessoa> agenda;

    cout << "--- Adicionando Pessoas na Agenda ---" << endl;
    // Adicionar pelo menos 3 objetos Pessoa ao vector [cite: 211]
    agenda.push_back(Pessoa("Isaac Newton", "9999-1643"));
    agenda.push_back(Pessoa("Albert Einstein", "9999-1879"));
    agenda.push_back(Pessoa("Marie Curie", "9999-1867"));

    cout << "\n--- Conteudo da Agenda ---" << endl;
    // Percorrer o vector utilizando um laço e imprimir nome e telefone
    // Este é um "range-based for loop", uma forma moderna e limpa de percorrer containers.
    for (Pessoa& pessoa : agenda) {
        pessoa.imprimirNome();
        pessoa.imprimirTelefone();
        cout << "--------------------" << endl;
    }

    cout << "\n--- Fim do programa, destruindo objetos ---" << endl;
    // Ao final da função main, o vector 'agenda' sai de escopo.
    // Isso faz com que o destrutor de cada objeto Pessoa dentro dele seja chamado automaticamente.

    return 0;
}
