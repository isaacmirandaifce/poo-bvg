#include "Aluno.h"
#include <cassert>

void test_aluno() {
    Aluno aluno("João", "senha123");
    assert(aluno.autenticar("senha123"));
    assert(!aluno.autenticar("senha_errada"));
    aluno.adicionarDisciplina("Matemática", 2023, 8.5);
    aluno.adicionarDisciplina("Física", 2023, 7.0);
    aluno.gerarRelatorio();
}

int main() {
    test_aluno();
    return 0;
}