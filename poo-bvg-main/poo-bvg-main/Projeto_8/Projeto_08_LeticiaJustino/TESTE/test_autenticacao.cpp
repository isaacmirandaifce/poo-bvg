#include <iostream>
#include <cassert>
#include "../src/headers/Aluno.h"
#include "../src/headers/Professor.h"

void test_autenticacao() {
    std::cout << "Testando sistema de autenticação..." << std::endl;
    
    // Teste de autenticação básica
    Aluno aluno("Aluno Teste", "aluno@teste.com", "A123", "minhasenha", "ADS");
    Professor professor("Prof Teste", "prof@teste.com", "P456", "senhaprof", "TI");
    
    // Testes de autenticação correta
    assert(aluno.autenticar("minhasenha") == true);
    assert(professor.autenticar("senhaprof") == true);
    
    // Testes de autenticação incorreta
    assert(aluno.autenticar("senhaerrada") == false);
    assert(professor.autenticar("professor") == false);
    
    // Teste de alteração de senha
    aluno.setSenha("novasenha123");
    assert(aluno.autenticar("novasenha123") == true);
    assert(aluno.autenticar("minhasenha") == false);
    
    std::cout << "Testes de autenticação passaram!" << std::endl;
}

void test_seguranca_senha() {
    std::cout << "Testando segurança de senhas..." << std::endl;
    
    Aluno aluno("Teste", "teste@email.com", "T001", "senhaforte", "ADS");
    
    // Teste que senha muito curta deve lançar exceção
    try {
        aluno.setSenha("abc");
        assert(false); // Não deve chegar aqui
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Senha deve ter pelo menos 6 caracteres");
    }
    
    // Teste que senha válida funciona
    try {
        aluno.setSenha("senhavalida123");
        assert(aluno.autenticar("senhavalida123"));
    } catch (...) {
        assert(false); // Não deve lançar exceção
    }
    
    std::cout << "Testes de segurança passaram!" << std::endl;
}

int main() {
    test_autenticacao();
    test_seguranca_senha();
    
    std::cout << "Todos os testes de autenticação passaram!" << std::endl;
    return 0;
}