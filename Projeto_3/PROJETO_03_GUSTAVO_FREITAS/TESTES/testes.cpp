#include <iostream>
#include <vector>
#include <cassert>
#include "../src/Pessoa.h"

void testConstrutorPadrao() {
    Pessoa p;
    assert(p.getNome() == "");
    assert(p.getTelefone() == "");
    std::cout << "Teste construtor padrão: OK\n";
}

void testConstrutorParametrizado() {
    Pessoa p("Teste", "(00) 0000-0000");
    assert(p.getNome() == "Teste");
    assert(p.getTelefone() == "(00) 0000-0000");
    std::cout << "Teste construtor parametrizado: OK\n";
}

void testSetters() {
    Pessoa p;
    p.setNome("Novo Nome");
    p.setTelefone("(99) 9999-9999");
    assert(p.getNome() == "Novo Nome");
    assert(p.getTelefone() == "(99) 9999-9999");
    std::cout << "Teste setters: OK\n";
}

int main() {
    testConstrutorPadrao();
    testConstrutorParametrizado();
    testSetters();
    
    std::cout << "Todos os testes passaram!\n";
    return 0;
}