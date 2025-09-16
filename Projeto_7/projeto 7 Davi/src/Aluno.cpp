#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& matricula, double media)
    : nome(nome), matricula(matricula), media(media) {}

void Aluno::adicionarDisciplina(const std::string& nomeDisciplina, int ano, double nota) {
    historico.push_back({nomeDisciplina, ano, nota});
}

const std::string& Aluno::getNome() const {
    return nome;
}

const std::string& Aluno::getMatricula() const {
    return matricula;
}

double Aluno::getMedia() const {
    return media;
}

const std::vector<DisciplinaHistorico>& Aluno::getHistorico() const {
    return historico;
}

void Aluno::imprimir() const {
    std::cout << "Aluno: " << nome << " | Matrícula: " << matricula << " | Média: " << media << std::endl;
}
