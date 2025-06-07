#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

using namespace std;

int main() {
    Aluno aluno1("Leticia Silva", "202501234", "Engenharia");

    Disciplina d1("Matemática", 60, 7.5);
    Disciplina d2("Física", 60, 5.0);

    aluno1.exibirInformacoes();

    Disciplina disciplinas[] = { d1, d2 };

    cout << "\nDisciplinas e Status:\n";
    for (const Disciplina& d : disciplinas) {
        cout << "- " << d.getNome() << ": Nota " << d.getNota();
        cout << " - " << (verificarAprovacao(d) ? "Aprovado" : "Reprovado") << endl;
    }

    return 0;
}