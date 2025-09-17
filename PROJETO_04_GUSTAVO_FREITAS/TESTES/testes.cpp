#include <iostream>
#include <cassert>
#include "../src/Aluno.h"
#include "../src/Disciplina.h"

void testAlunoConstrutor() {
    Aluno aluno("Teste", "123", "ADS");
    assert(aluno.getNome() == "Teste");
    assert(aluno.getMatricula() == "123");
    assert(aluno.getCurso() == "ADS");
    std::cout << "Teste construtor Aluno: OK\n";
}

void testDisciplinaConstrutor() {
    Disciplina disciplina("Matemática", 60, 7.0f);
    assert(disciplina.getNome() == "Matemática");
    assert(disciplina.getCargaHoraria() == 60);
    assert(disciplina.getNota() == 7.0f);
    std::cout << "Teste construtor Disciplina: OK\n";
}

void testVerificacaoAprovacao() {
    Disciplina aprovada("Aprovada", 60, 6.0f);
    Disciplina reprovada("Reprovada", 60, 5.9f);
    
    assert(verificarAprovacao(aprovada) == true);
    assert(verificarAprovacao(reprovada) == false);
    std::cout << "Teste verificação aprovação: OK\n";
}

int main() {
    testAlunoConstrutor();
    testDisciplinaConstrutor();
    testVerificacaoAprovacao();
    
    std::cout << "\nTodos os testes passaram com sucesso!\n";
    return 0;
}