#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

using namespace std;

int main() {
    Aluno aluno1("Maria Silva", "2023001", "ADS");
    Disciplina d1("Matemática", 60);
    Disciplina d2("Programação", 80);

    d1.setNota(7.5);
    d2.setNota(5.0);

    aluno1.exibirInformacoes();

    cout << "\nStatus nas Disciplinas:\n";
    verificarAprovacao(d1);
    verificarAprovacao(d2);

    return 0;
}
