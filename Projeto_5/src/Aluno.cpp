#include "Aluno.h"
#include <iostream>
void Aluno::gerarRelatorio() {
    std::cout << "Aluno: " << nome << "\nMatricula: " << matricula << "\nCurso: " << curso << std::endl;
}
