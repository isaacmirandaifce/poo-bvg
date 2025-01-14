// main.cpp
#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno("Gabriely Morais", "20233000023", "Análise e Desenvolvimento de Sistemas");

    Disciplina disciplina1("POO", 9.0, 6.5);
    Disciplina disciplina2("Etica", 8.0, 5.8);

    aluno.exibirInformacoes();

    std::cout << "\nResultados:\n";
    std::cout << disciplina1.getNome() << ": "
              << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << "\n";
    std::cout << disciplina2.getNome() << ": "
              << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << "\n";

    return 0;
}
