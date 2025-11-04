#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Pessoa.h"

using namespace std;

int main() {
    vector<Pessoa> pessoas;
    int n = 0;
    // Vetor que armazena objetos Pessoa.

    cout << "Quantas pessoas deseja inserir? ";
    // Leitura do número de entradas. Se a leitura falhar (por exemplo,
    // o usuário digita uma string), o programa retorna com código 1.
    if (!(cin >> n)) return 1;

    // Após ler um número com `operator>>`, o caractere de nova linha
    // fica no buffer. `cin.ignore(...)` limpa o restante da linha para
    // que chamadas subsequentes a `getline` funcionem corretamente.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Loop de leitura: para cada pessoa, pedimos nome e telefone.
    // Usamos `getline` para permitir nomes com espaços.
    for (int i = 0; i < n; ++i) {
        string nome, telefone;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Telefone: ";
        getline(cin, telefone);

        // `emplace_back` constrói o objeto diretamente no vetor usando
        // o construtor que recebe (nome, telefone). Isso evita cópias
        pessoas.emplace_back(nome, telefone);
    }

    // Impressão da lista de pessoas armazenadas.
    cout << "\nLista de pessoas:\n";
    for (const Pessoa& p : pessoas) {
        p.imprimirNome();
        p.imprimirTelefone();
        cout << "------------------------" << endl;
    }

    return 0;
}