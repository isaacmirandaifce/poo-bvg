#include <iostream>
#include "aluno.h"
#include "disciplina.h"
using namespace std;
int main() {
    // create object aluno
    Aluno aluno("Maria Fernanda", "2336977", "ADS");

    // create object disciplina
    Disciplina d1("Engenharia de Software", 80, 8.5f);
    Disciplina d2("POO", 80, 8.3f);

    // exibir informações do aluno
    aluno.exibirInformacoes();

    // verificar a aprovação nas disciplinas
    cout << "Disciplina: Engenharia de Software " << (verifiedAprovacao(d1) ? " Aprovado" : " Reprovado") << "\n" << endl;
    cout << "Disciplina: POO " << (verifiedAprovacao(d2) ? " Aprovado" : " Reprovado") << "\n" << endl;

    return 0;
}