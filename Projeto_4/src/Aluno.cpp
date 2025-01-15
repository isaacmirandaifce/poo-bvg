#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso)
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nMatricula: " << matricula
              << "\nCurso: " << curso << std::endl;
}

void Aluno::adicionarDisciplina(const Disciplina& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::exibirDisciplinas() const {
    for (const auto& disciplina : disciplinas) {
        std::cout << "Disciplina: " << disciplina.getNome()
                  << ", Nota: " << disciplina.getNota() << std::endl;
    }
}
