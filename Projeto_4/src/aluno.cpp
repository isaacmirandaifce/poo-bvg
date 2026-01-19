#include "aluno.h"
#include <iostream>

Aluno::Aluno() {
    nome = "";
    matricula = "";
    curso = "";
}

Aluno::Aluno(std::string nome, std::string matricula, std::string curso) {
    this->nome = nome;
    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::exibirInformacoes() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}
