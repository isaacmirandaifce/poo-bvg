#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {
    tipo = "Aluno";
}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

void Aluno::adicionarNota(float nota) {
    notas.push_back(nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno\n";
    std::cout << "Nome: " << nome << "\nMatricula: " << matricula << "\nCurso: " << curso << "\nDisciplinas:\n";
    for (const auto& d : disciplinasCursadas) {
        std::cout << "- " << d << "\n";
    }
    std::cout << "----------------------\n";
}

// Sobrecarga
void Aluno::exibirInformacoes() const {
    std::cout << "Aluno: " << nome << " | Curso: " << curso << "\n";
}

void Aluno::exibirInformacoes(bool comNotas) const {
    std::cout << "Aluno: " << nome << "\nDisciplinas:\n";
    for (size_t i = 0; i < disciplinasCursadas.size(); ++i) {
        std::cout << "- " << disciplinasCursadas[i];
        if (comNotas && i < notas.size()) {
            std::cout << " | Nota: " << notas[i];
        }
        std::cout << "\n";
    }
}
