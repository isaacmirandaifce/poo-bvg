//Código de Alissa Garcia ADS S3

//Contém a função principal e manipulação do `vector`

#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;

int main() {

    std::vector <Pessoa> listaPessoa;

    // Criando objetos Pessoa e adicionando ao vector
        for(int i = 0; i < 3; i++){
            std::string nome, telefone;

            std::cout << "Digite o nome da pessoa " << i+1 << ":";
            getline(std::cin, nome);
            //Utilizando o std::cin para entrada de dados.

            std::cout << "Digite o telefone da pessoa " << i+1 << ":";
            getline(std::cin, telefone);
            //Utilizando o std::cin para entrada de dados.
            
            listaPessoa.emplace_back(nome, telefone);
            //Colocando no vetor

            std::cout << endl;

            //endl é somente quebra de linha

        }
    

    // Percorrendo o vector e exibindo informações
        for (int i = 0; i < 3; i++) {
        
            listaPessoa[i].imprimirNome();
            listaPessoa[i].imprimirTelefone();

        }

    return 0;
}