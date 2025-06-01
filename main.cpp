#include <iostream>     // Biblioteca para entrada e saída de dados
#include <vector>       // Biblioteca para usar o container std::vector
#include "Pessoa.h"     // Inclusão da definição da classe Pessoa

using namespace std;    // Para evitar escrever std:: em tudo

int main() {
    // Criação de um vetor de objetos do tipo Pessoa
    vector<Pessoa> pessoas;

    // Adicionando 3 objetos Pessoa ao vetor usando o construtor parametrizado
    pessoas.push_back(Pessoa("Carlos Silva", "99999-1234"));
    pessoas.push_back(Pessoa("Maria Oliveira", "98888-4321"));
    pessoas.push_back(Pessoa("João Santos", "97777-5678"));

    // Percorrendo o vetor e exibindo os dados de cada pessoa
    for (int i = 0; i < pessoas.size(); ++i) {
        pessoas[i].imprimirNome();       // Imprime o nome da pessoa
        pessoas[i].imprimirTelefone();   // Imprime o telefone da pessoa
        cout << "-------------------" << endl; // Separador visual
    }

    return 0;
}
