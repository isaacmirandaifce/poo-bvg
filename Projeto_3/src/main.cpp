#include <iostream>
#include <vector>
#include "Contato.h"

int main() {
    //Container dinâmico para armazenar os contatos de clientes corporativos
    std::vector<Contato> contatos;
    
    //Reserva espaço para 3 contatos sem criar nenhum ainda, para evitar poluição visual
    contatos.reserve(3);

    //Instanciação de 3 contatos utilizando push_back()
    contatos.push_back(Contato("Rockstar Games", "(88) 3637-6666"));
    contatos.push_back(Contato("Nintendo", "(85) 3030-2026"));
    contatos.push_back(Contato("Playstation", "(11) 4002-8922"));

    std::cout << "---------- CONTATOS -----------" << std::endl;

    //Iteração segura pelo vector utilizando size() para não estourar o limite
    for (size_t i = 0; i < contatos.size(); i++) {
        std::cout << "Contato #" << (i + 1) << std::endl;
        contatos[i].imprimirNome();
        contatos[i].imprimirTelefone();
    }

    return 0;
}