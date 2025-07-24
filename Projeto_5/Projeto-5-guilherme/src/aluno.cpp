#include "aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {
    tipo = "Aluno";
}

Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const Disciplina& d) {
    disciplinas.push_back(d);
}

void Aluno::gerarRelatorio() const {
    std::cout << "=== Relatório do Aluno ===\n"
              << "Nome: " << nome << "\n"
              << "Matrícula: " << matricula << "\n"
              << "Curso: " << curso << "\n"
              << "Disciplinas:\n";

    for (const auto& d : disciplinas) {
        d.exibirDados();
    }
}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n"
              << "Matrícula: " << matricula << "\n"
              << "Curso: " << curso << "\n";
}

void Aluno::exibirInformacoes(bool comNotas) const {
    exibirInformacoes();
    if (comNotas) {
        std::cout << "--- Notas ---\n";
        for (const auto& d : disciplinas) {
            std::cout << d.getNome() << ": " << d.getNota() << "\n";
        }
    }
}
