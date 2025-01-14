#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso)
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
}

void Aluno::adicionarDisciplina(const Disciplina& disciplina) {
    disciplinas.push_back(disciplina);
}

std::vector<Disciplina> Aluno::getDisciplinas() const {
    return disciplinas;
}
