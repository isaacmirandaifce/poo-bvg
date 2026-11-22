/**
 * @file main.cpp
 * @brief Ponto de entrada do módulo de Contatos B2B.
 *
 * Usa std::vector (array dinâmico da STL) no lugar de arrays fixos em C.
 */

#include <iostream>
#include <vector>
#include "Contato.h"

int main() {
    std::vector<Contato> contatos;

    // Reserva espaço para 3 contatos de uma vez. Sem isso, o vector
    // realocaria memória a cada push_back, copiando os objetos e
    // destruindo as cópias antigas (gerando logs extras do destrutor).
    contatos.reserve(3);

    std::cout << "=== Cadastrando contatos ===" << std::endl;
    contatos.push_back(Contato("Ana Souza - TechNova Ltda",
                               "(11) 98765-4321"));
    contatos.push_back(Contato("Bruno Lima - Agro Forte S.A.",
                               "(62) 99876-5432"));
    contatos.push_back(Contato("Carla Mendes - LogiSul Transportes",
                               "(51) 97654-3210"));

    std::cout << "\n=== Lista de Contatos B2B ===" << std::endl;
    // Iteração segura: i vai de 0 até size()-1, nunca passa do limite.
    for (std::size_t i = 0; i < contatos.size(); i++) {
        std::cout << "--- Contato " << (i + 1) << " ---" << std::endl;
        contatos[i].imprimirNome();
        contatos[i].imprimirTelefone();
    }

    std::cout << "\n=== Encerrando o programa ===" << std::endl;
    return 0;
    // Ao sair do main, o vector sai de escopo e destrói cada Contato,
    // disparando o log do destrutor para cada um.
}
