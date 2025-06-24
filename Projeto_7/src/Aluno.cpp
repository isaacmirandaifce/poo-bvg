#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& matricula, double media)
    : nome(nome), matricula(matricula), mediaGeral(media) {}

std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::getMatricula() const {
    return matricula;
}

double Aluno::getMediaGeral() const {
    return mediaGeral;
}

void Aluno::adicionarDisciplinaCursada(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

const std::vector<std::string>& Aluno::getDisciplinasCursadas() const {
    return disciplinasCursadas;
}

void Aluno::imprimir() const {
    std::cout << "Aluno: " << nome << " (Matricula: " << matricula << ", Media: " << mediaGeral << ")" << std::endl;
}