#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string &nome, const std::string &matricula, const std::string &curso)
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const Disciplina &disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::exibirInformacoes() const {
    std::cout << "Aluno: " << nome << "\n"
              << "Matricula: " << matricula << "\n"
              << "Curso: " << curso << "\n";

    std::cout << "\nDisciplinas:\n";
    for (const auto &disciplina : disciplinas) {
        std::cout << "- " << disciplina.getNome() << ": Nota = " << disciplina.getNota();
        if (verificarAprovacao(disciplina)) {
            std::cout << " (Aprovado)";
        } else {
            std::cout << " (Reprovado)";
        }
        std::cout << "\n";
    }
}

std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::getMatricula() const {
    return matricula;
}

std::string Aluno::getCurso() const {
    return curso;
}