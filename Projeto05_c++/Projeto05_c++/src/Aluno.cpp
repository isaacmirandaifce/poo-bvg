#include "../include/Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno:\n"
              << "Nome: " << nome << "\n"
              << "Matricula: " << matricula << "\n"
              << "Curso: " << curso << "\n"
              << "Disciplinas:\n";
    for (const auto& disciplina : disciplinas) {
        std::cout << " - " << disciplina.getNome() << " (Nota: " << disciplina.getNota() << ")\n";
    }
}

void Aluno::adicionarDisciplina(const Disciplina& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::exibirInformacoes(bool comNotas) const {
    std::cout << "Informacoes do Aluno:\n"
              << "Nome: " << nome << "\n"
              << "Matricula: " << matricula << "\n"
              << "Curso: " << curso << "\n";
    if (comNotas) {
        std::cout << "Disciplinas e Notas:\n";
        for (const auto& disciplina : disciplinas) {
            std::cout << " - " << disciplina.getNome() << " (Nota: " << disciplina.getNota() << ")\n";
        }
    }
}

