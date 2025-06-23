#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina, float nota) {
    disciplinas.push_back(disciplina);
    notas.push_back(nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n";
    std::cout << "Nome: " << nome << "\nMatrícula: " << matricula << "\nCurso: " << curso << "\n";
    std::cout << "Disciplinas cursadas:\n";
    for (size_t i = 0; i < disciplinas.size(); ++i) {
        std::cout << "- " << disciplinas[i] << " (Nota: " << notas[i] << ")\n";
    }
}

void Aluno::exibirInformacoes() const {
    std::cout << "Aluno: " << nome << " | Matrícula: " << matricula << " | Curso: " << curso << "\n";
}

void Aluno::exibirInformacoes(bool mostrarNotas) const {
    exibirInformacoes();
    if (mostrarNotas) {
        std::cout << "Notas:\n";
        for (size_t i = 0; i < disciplinas.size(); ++i) {
            std::cout << "- " << disciplinas[i] << ": " << notas[i] << "\n";
        }
    }
}