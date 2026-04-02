#include "Monitor.h"
#include <iostream>

using namespace std;

// Inicialização direta da base virtual 'Usuario' é necessária na classe mais derivada
Monitor::Monitor(string nome, string email, string matricula, string curso, string area)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, area, {})
{
}

void Monitor::gerarRelatorio() {
    cout << "--- Relatorio de Monitor ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Vinculo: " << tipo << endl;
    cout << "Curso (Aluno): " << curso << endl;
    cout << "Area de Apoio (Professor): " << areaDeAtuacao << endl;
}
