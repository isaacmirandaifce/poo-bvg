#include "Aluno.h"
#include <iostream>

#include <iomanip>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso)
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}

const std::string& Aluno::getNome() const { return nome; }
const std::string& Aluno::getMatricula() const { return matricula; }
const std::string& Aluno::getCurso() const { return curso; }

void Aluno::adicionarDisciplina(const Disciplina& d) {
    disciplinas.push_back(d);
}

void Aluno::exibirDisciplinas() const {
    if (disciplinas.empty()) {
        std::cout << "Nenhuma disciplina associada." << std::endl;
        return;
    }

    std::cout << "Disciplinas e situação:" << std::endl;
    for (const auto& d : disciplinas) {
        std::cout << "- " << d.getNome() << " (CH: " << d.getCargaHoraria() << ") - Nota: "
                  << std::fixed << std::setprecision(1) << d.getNota()
                  << " -> " << (verificarAprovacao(d) ? "Aprovado" : "Reprovado") << std::endl;
    }
}
