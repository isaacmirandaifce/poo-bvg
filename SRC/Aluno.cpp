#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& email, 
             const std::string& matricula)
    : Usuario(nome, email, "Aluno"), matricula(matricula) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Aluno: " << nome << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Disciplinas matriculadas: " << disciplinas.size() << "\n";
}

void Aluno::matricular(Disciplina* disciplina) {
    disciplinas.push_back(disciplina);
    disciplina->matricularAluno(nome);
}

void Aluno::matricular(Disciplina* disciplina, float notaInicial) {
    matricular(disciplina);
    notas[disciplina->getCodigo()] = notaInicial;
}

void Aluno::adicionarNota(const std::string& codigoDisciplina, float nota) {
    notas[codigoDisciplina] = nota;
}

void Aluno::listarDisciplinas() const {
    std::cout << "Disciplinas de " << nome << ":\n";
    for (const auto& disc : disciplinas) {
        std::cout << " - " << disc->getNome() << " (" << disc->getCodigo() << ")";
        if (notas.find(disc->getCodigo()) != notas.end()) {
            std::cout << " - Nota: " << notas.at(disc->getCodigo());
        }
        std::cout << "\n";
    }
}

std::string Aluno::getMatricula() const { return matricula; }