#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(std::string disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << "\nCurso: " << curso << "\nMatrícula: " << matricula << "\n";
    std::cout << "Disciplinas:\n";
    for (const auto& d : disciplinas) std::cout << "- " << d << "\n";
}

void Aluno::gerarRelatorio(bool comNotas) const {
    gerarRelatorio();
    if (comNotas) {
        std::cout << "[Notas ainda não implementadas]\n";
    }
}
