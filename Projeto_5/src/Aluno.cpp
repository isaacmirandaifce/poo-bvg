#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso, const std::string& email)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const Disciplina& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
}

void Aluno::exibirInformacoes(bool comNotas) const {
    exibirInformacoes();
    if (comNotas) {
        for (const auto& disciplina : disciplinas) {
            std::cout << "Disciplina: " << disciplina.getNome()
                      << " - Nota: " << disciplina.getNota() << "\n";
        }
    }
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n";
    exibirInformacoes(true);
}
