#include "Aluno.h"

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(std::string nome, std::string matricula, std::string curso) {
    this->nome = nome;
    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::exibirInformacoes() const {
    std::cout << "Aluno: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}
