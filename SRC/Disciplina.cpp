#include "Disciplina.h"
#include <iostream>

Disciplina::Disciplina(const std::string& codigo, const std::string& nome,
                       const std::string& professor, int creditos)
    : codigo(codigo), nome(nome), professor(professor), creditos(creditos) {}

void Disciplina::matricularAluno(const std::string& aluno) {
    alunosMatriculados.push_back(aluno);
}

void Disciplina::listarAlunos() const {
    std::cout << "Alunos matriculados em " << nome << ":\n";
    for (const auto& aluno : alunosMatriculados) {
        std::cout << " - " << aluno << "\n";
    }
}

std::string Disciplina::getCodigo() const { return codigo; }
std::string Disciplina::getNome() const { return nome; }
std::string Disciplina::getProfessor() const { return professor; }
int Disciplina::getCreditos() const { return creditos; }