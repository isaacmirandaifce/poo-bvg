#include <iostream>
#include <string>
#include <vector>
#include "contato.h"

/**
 * @brief Função principal responsável por inicializar e exibir os contatos.
 * @return 0 caso a execução seja bem-sucedida.
 */
int main()
{

    std::vector<Contato> contatos;

    contatos.push_back(AdicionarContatos("Fulano", "(88) 9999-991"));

    contatos.push_back(AdicionarContatos("Fulana", "(88) 9999-992"));

    contatos.push_back(AdicionarContatos("Julano", "(88) 9999-993"));

    for (int i = 0; i < contatos.size(); i++)
    {
        std::cout << "\nContato " << i + 1 << ":\n";
        contatos.at(i).imprimirNome();
        contatos.at(i).imprimirTelefone();
        std::cout << '\n';
    }

    return 0;
}