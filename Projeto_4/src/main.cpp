#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

using namespace std;

int main() {
    Aluno aluno("Maria Silva", "202500123", "Engenharia de Software");

    Disciplina d1("Programação", 60, 8.5);
    Disciplina d2("Matemática", 60, 5.9);

    cout << "=== INFORMAÇÕES DO ALUNO ===" << endl;
    aluno.exibirInformacoes();
    cout << endl;
    
    cout << "=== STATUS DAS DISCIPLINAS ===" << endl;

    cout << "Disciplina: " << d1.getNome() << endl;
    cout << "Nota: " << d1.getNota() << endl;
    cout << "Status: " << (verificarAprovacao(d1) ? "Aprovado" : "Reprovado") << endl << endl;

    cout << "Disciplina: " << d2.getNome() << endl;
    cout << "Nota: " << d2.getNota() << endl;
    cout << "Status: " << (verificarAprovacao(d2) ? "Aprovado" : "Reprovado") << endl;

    return 0;
}
