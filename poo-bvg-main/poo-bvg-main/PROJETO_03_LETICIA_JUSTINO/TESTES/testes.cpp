#include <iostream>
#include <vector>
#include <cassert>
#include "../src/Pessoa.h"


// ------------------------------
// Função de teste: Construtor padrão
// ------------------------------
void testConstrutorPadrao() {
    Pessoa p;  // Cria objeto usando o construtor padrão

    // Verifica se os atributos foram inicializados corretamente (vazios)
    assert(p.getNome() == "");
    assert(p.getTelefone() == "");

    // Se chegar até aqui, significa que o teste passou
    std::cout << "Teste construtor padrão: OK\n";
}


// ------------------------------
// Função de teste: Construtor parametrizado
// ------------------------------
void testConstrutorParametrizado() {
    // Cria objeto com valores iniciais
    Pessoa p("Teste", "(00) 0000-0000");

    // Verifica se os valores foram atribuídos corretamente
    assert(p.getNome() == "Teste");
    assert(p.getTelefone() == "(00) 0000-0000");

    std::cout << "Teste construtor parametrizado: OK\n";
}


// ------------------------------
// Função de teste: Setters (modificadores de atributos)
// ------------------------------
void testSetters() {
    Pessoa p;  // Cria objeto com valores padrão

    // Altera os atributos usando os métodos set
    p.setNome("Novo Nome");
    p.setTelefone("(99) 9999-9999");

    // Verifica se os valores foram atualizados corretamente
    assert(p.getNome() == "Novo Nome");
    assert(p.getTelefone() == "(99) 9999-9999");

    std::cout << "Teste setters: OK\n";
}


// ------------------------------
// Função principal — executa todos os testes
// ------------------------------
int main() {
    // Chama cada função de teste separadamente
    testConstrutorPadrao();
    testConstrutorParametrizado();
    testSetters();
    
    // Se todos os testes passarem, exibe a mensagem final
    std::cout << "Todos os testes passaram!\n";
    return 0; // Indica que o programa terminou com sucesso
}
