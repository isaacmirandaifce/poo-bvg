#include "Aluno.h"
#include "Persistencia.h"
#include <cassert>

void testAluno() {
    Aluno aluno(1, "João Silva");
    assert(aluno.getId() == 1);
    assert(aluno.getNome() == "João Silva");
}

void testPersistencia() {
    std::vector<Aluno> alunos = {Aluno(1, "João Silva"), Aluno(2, "Maria Oliveira")};
    Persistencia::salvarAlunos("data/test_alunos.txt", alunos);

    auto alunosCarregados = Persistencia::carregarAlunos("data/test_alunos.txt");
    assert(alunosCarregados.size() == 2);
    assert(alunosCarregados[0].getNome() == "João Silva");
    assert(alunosCarregados[1].getNome() == "Maria Oliveira");
}

int main() {
    testAluno();
    testPersistencia();
    std::cout << "Todos os testes passaram!\n";
    return 0;
}