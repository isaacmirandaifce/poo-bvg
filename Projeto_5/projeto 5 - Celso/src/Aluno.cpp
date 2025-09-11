#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::gerarRelatorio() const {
    std::cout << "Nome: " << nome << "\nMatrícula: " << matricula << "\nCurso: " << curso << std::endl;
}

void Aluno::exibirInformacoes(bool comNotas) const {
    gerarRelatorio();
    if (comNotas) {
        std::cout << "Disciplinas Cursadas: " << std::endl;
        for (const auto& disciplina : disciplinasCursadas) {
            std::cout << " - " << disciplina << std::endl;
        }
    }
}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}
