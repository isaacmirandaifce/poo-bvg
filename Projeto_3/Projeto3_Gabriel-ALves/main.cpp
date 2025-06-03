#include <iostream> // Para std::cout, std::endl 
#include <vector>   // Para std::vector 
#include "pessoa.h" // Inclui a declaração da classe Pessoa

// Utiliza o namespace std para simplificar a escrita do código 
using namespace std;

int main() {
    // Criar um container std::vector para armazenar objetos do tipo Pessoa 
    vector<Pessoa> agenda;

    cout << "--- Adicionando Pessoas ao Vetor ---" << endl;
    // Adicionar pelo menos 3 objetos Pessoa ao vector 
    agenda.push_back(Pessoa("Ada Lovelace", "98765-4321"));
    agenda.push_back(Pessoa("Grace Hopper", "12345-6789"));
    agenda.push_back(Pessoa("Alan Turing", "11235-8132"));
    cout << "-----------------------------------" << endl << endl;

    cout << "--- Imprimindo Dados das Pessoas no Vetor ---" << endl;
    // Percorrer o vector utilizando um laço e imprimir o nome e telefone de cada pessoa 
    for (size_t i = 0; i < agenda.size(); ++i) {
        cout << "Pessoa " << i + 1 << ":" << endl;
        agenda[i].imprimirNome();
        agenda[i].imprimirTelefone();
        if (i < agenda.size() - 1) {
            cout << "---" << endl;
        }
    }
    cout << "------------------------------------------" << endl << endl;

    cout << "--- Fim do programa, objetos Pessoa serao destruidos ---" << endl;
    // Os destrutores dos objetos Pessoa no vetor 'agenda' serão chamados automaticamente
    // quando 'agenda' sair de escopo (ao final da função main).

    return 0;
}