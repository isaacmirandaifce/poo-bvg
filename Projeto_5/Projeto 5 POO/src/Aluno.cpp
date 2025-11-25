#include "Aluno.h"
#include <iostream>
#include <iomanip>

Aluno::Aluno() : Usuario("", "", "Aluno"), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome,
             const std::string& email,
             const std::string& matricula,
             const std::string& curso)
    : Usuario(nome, email, "Aluno"),
      matricula(matricula),
      curso(curso) {}

void Aluno::gerarRelatorio() const {
    std::cout << "[Aluno] Nome: " << nome
              << " | Matrícula: " << matricula
              << " | Curso: " << curso << std::endl;

    listarDisciplinas();
}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}

void Aluno::exibirInformacoes(bool comNotas) const {
    exibirInformacoes();
    if (comNotas) {
        listarDisciplinas();
    }
}

void Aluno::adicionarDisciplina(const Disciplina& d) {
    disciplinas.push_back(d);
}

void Aluno::listarDisciplinas() const {
    if (disciplinas.empty()) {
        std::cout << "Nenhuma disciplina cadastrada para este aluno." << std::endl;
        return;
    }

    std::cout << "Disciplinas cursadas:" << std::endl;
    for (const auto& d : disciplinas) {
        std::cout << "- " << d.getNome()
                  << " (CH: " << d.getCargaHoraria() << ") "
                  << "| Nota: " << std::fixed << std::setprecision(1) << d.getNota()
                  << " -> " << (aprovadoNaDisciplina(d) ? "Aprovado" : "Reprovado")
                  << std::endl;
    }
}

const std::string& Aluno::getMatricula() const {
    return matricula;
}

const std::string& Aluno::getCurso() const {
    return curso;
}
