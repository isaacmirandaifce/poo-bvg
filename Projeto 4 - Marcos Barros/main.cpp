#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"
using namespace std;

int main() {
    Aluno aluno1("Marcos Barros", "20251234", "Análise e Desenvolvimento de Sistemas");

    Disciplina d1("Programação", 60, 7.5);
    Disciplina d2("Redes", 60, 5.0);

    aluno1.exibirInformacoes();

    Disciplina disciplinas[] = {d1, d2};

    for (Disciplina d : disciplinas) {
        cout << "\nDisciplina: " << d.getNome() << endl;
        cout << "Nota: " << d.getNota() << endl;

        if (verificarAprovacao(d)) {
            cout << "Status: Aprovado\n";
        } else {
            cout << "Status: Reprovado\n";
        }
    }

    return 0;
}
