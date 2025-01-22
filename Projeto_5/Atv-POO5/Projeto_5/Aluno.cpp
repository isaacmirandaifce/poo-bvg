#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Matrícula: " << matricula << "\nCurso: " << curso << "\n";
    std::cout << "Disciplinas Cursadas:\n";
    for (const auto& disciplina : disciplinasCursadas) {
        std::cout << "- " << disciplina << "\n";
    }
}

void Aluno::gerarRelatorio(bool incluirNotas) const {
    // Implementação para exibir informações com notas.
}
