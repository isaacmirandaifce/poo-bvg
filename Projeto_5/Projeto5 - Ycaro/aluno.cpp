#include "aluno.h"
#include <iostream>

aluno::aluno() {}

aluno::aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : usuario(nome, email, "aluno"), matricula(matricula), curso(curso) {}

void aluno::adicionarDisciplina(std::string disciplina) {
    disciplinas.push_back(disciplina);
}

void aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << "\nMatricula: " << matricula
              << "\nCurso: " << curso << "\nDisciplinas:\n";
    for (const auto& d : disciplinas) {
        std::cout << "- " << d << "\n";
    }
}

void aluno::gerarRelatorio(bool mostrarNotas) const {
    gerarRelatorio();
    if (mostrarNotas) {
        std::cout << "Notas: (notas aqui)\n";
    }
}