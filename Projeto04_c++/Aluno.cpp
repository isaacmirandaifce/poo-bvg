#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso)
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n"
              << "Matricula: " << matricula << "\n"
              << "Curso: " << curso << "\n";
}

void Aluno::adicionarDisciplina(const Disciplina& disciplina) {
    disciplinas.push_back(disciplina);
}

const std::string& Aluno::getNome() const {
    return nome;
}

const std::vector<Disciplina>& Aluno::getDisciplinas() const {
    return disciplinas;
}