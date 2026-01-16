// Inclui biblioteca padrão para entrada e saída de dados (cout, cin)
#include <iostream>

// Inclui a biblioteca que permite o uso de vetores dinâmicos (std::vector)
#include <vector>

// Inclui o cabeçalho da classe Pessoa (definida em outro arquivo)
#include "Pessoa.h"

// Função que exibe a lista de pessoas cadastradas
// Recebe um vetor constante de objetos Pessoa (não pode ser alterado)
void exibirListaPessoas(const std::vector<Pessoa>& pessoas) {
    std::cout << "\nLista de Pessoas:\n";
    std::cout << "-----------------\n";
    
    // Percorre o vetor de pessoas e chama métodos para exibir seus dados
    for (const auto& pessoa : pessoas) {
        pessoa.imprimirNome();      // Mostra o nome da pessoa
        pessoa.imprimirTelefone();  // Mostra o telefone da pessoa
        std::cout << std::endl;     // Linha em branco para separar cada pessoa
    }
}

// Função principal do programa
int main() {
    // Cria um vetor de objetos do tipo Pessoa
    std::vector<Pessoa> pessoas;
    
    // Adiciona objetos Pessoa diretamente ao vetor (emplace_back cria no local)
    pessoas.emplace_back("João Silva", "(11) 9999-8888");
    pessoas.emplace_back("Luis Alves", "(21) 7777-6666");
    pessoas.emplace_back("Carla Silva", "(31) 5555-4444");
    
    // Chama a função para exibir todos os dados cadastrados
    exibirListaPessoas(pessoas);
    
    // Retorna 0 indicando que o programa terminou sem erros
    return 0;
}