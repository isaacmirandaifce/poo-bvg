#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno("Dagoberto", "60607070", "Analise e Desenvolvimento de Sistemas");

    Disciplina disciplina1("POO", 60, 7.5f);
    Disciplina disciplina2("Logica de programação", 40, 5.0f);

    aluno.exibirInformacoes();

    std::cout << "\nStatus de Aprovação:\n";
    std::cout << "Disciplina: " << "Poo" << " - "
              << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << "\n";
    std::cout << "Disciplina: " << "Logica de programa" << " - "
              << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << "\n";

    return 0;
}