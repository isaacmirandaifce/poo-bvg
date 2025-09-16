#include "Monitor.h"
#include <iostream>
using namespace std;

Monitor::Monitor() {}

Monitor::Monitor(string nome, string email, string curso, int matricula, string disciplina, string titulacao)
    : Aluno(nome, email, curso, matricula), Professor(nome, email, disciplina, titulacao) {}

void Monitor::gerarRelatorio() const {
    cout << "Monitor: " << Aluno::nome << endl;
    cout << "Email: " << Aluno::email << endl;
    cout << "Curso: " << getCurso() << endl;
    cout << "Matrícula: " << getMatricula() << endl;
    cout << "Disciplina Monitorada: " << getDisciplina() << endl;
    cout << "Titulação do Monitor (como professor): " << getTitulacao() << endl;
}
