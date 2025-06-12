#include "Aluno.h"
#include <iostream>

Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << "\nMatricula: " << matricula
              << "\nCurso: " << curso << "\nDisciplinas:\n";
    for (const auto& d : disciplinas)
        std::cout << "- " << d << "\n";
}

void Aluno::gerarRelatorio(bool incluirNotas) const {
    gerarRelatorio();
    if (incluirNotas) {
        std::cout << "(Notas simuladas nao implementadas)\n";
    }
}
