#include <iostream>
#include <cassert>
#include "../src/Aluno.h"
#include "../src/Disciplina.h"

using namespace std;

void testarDisciplina() {
    Disciplina d("História", 40, 7.0);
    assert(d.getNome() == "História");
    assert(d.getNota() == 7.0);
    assert(verificarAprovacao(d) == true);

    d.setNota(5.5);
    assert(d.getNota() == 5.5);
    assert(verificarAprovacao(d) == false);
    cout << "Teste de Disciplina passou.\n";
}

void testarAluno() {
    Aluno a("Carlos", "202500001", "Direito");
    a.exibirInformacoes(); // teste visual
    cout << "Teste de Aluno (visual) exibido com sucesso.\n";
}

int main() {
    testarDisciplina();
    testarAluno();
    cout << "Todos os testes foram executados.\n";
    return 0;
}