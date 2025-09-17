#include <iostream>
#include <sstream>
#include <cassert>
#include "../src/headers/Aluno.h"
#include "../src/headers/Professor.h"

void test_relatorio_aluno() {
    std::cout << "Testando relatório do aluno..." << std::endl;
    
    Aluno aluno("João Silva", "joao@email.com", "2023001", "senha123", "ADS");
    aluno.adicionarDisciplina("Programação OO", 2023, 8.5);
    aluno.adicionarDisciplina("Banco de Dados", 2023, 9.0);
    
    // Redirecionar saída para stringstream para testar
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    aluno.gerarRelatorio();
    
    std::cout.rdbuf(oldCout);
    
    std::string result = output.str();
    
    // Verificar se contém informações esperadas
    assert(result.find("João Silva") != std::string::npos);
    assert(result.find("ADS") != std::string::npos);
    assert(result.find("8.75") != std::string::npos); // Média
    assert(result.find("Programação OO") != std::string::npos);
    
    std::cout << "Teste de relatório do aluno passou!" << std::endl;
}

void test_relatorio_professor() {
    std::cout << "Testando relatório do professor..." << std::endl;
    
    Professor professor("Maria Santos", "maria@email.com", "PROF001", "senha123", "Tecnologia");
    professor.adicionarDisciplina("Programação OO");
    professor.adicionarDisciplina("Estrutura de Dados");
    
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    professor.gerarRelatorio();
    
    std::cout.rdbuf(oldCout);
    
    std::string result = output.str();
    
    assert(result.find("Maria Santos") != std::string::npos);
    assert(result.find("Tecnologia") != std::string::npos);
    assert(result.find("Programação OO") != std::string::npos);
    
    std::cout << "Teste de relatório do professor passou!" << std::endl;
}

int main() {
    test_relatorio_aluno();
    test_relatorio_professor();
    
    std::cout << "Todos os testes de relatórios passaram!" << std::endl;
    return 0;
}