#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso) 
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
}

const std::string& Aluno::getNome() const {
    return nome;
}

const std::string& Aluno::getMatricula() const {
    return matricula;
}

const std::string& Aluno::getCurso() const {
    return curso;
}

void Aluno::setNome(const std::string& nome) {
    this->nome = nome;
}

void Aluno::setMatricula(const std::string& matricula) {
    this->matricula = matricula;
}

void Aluno::setCurso(const std::string& curso) {
    this->curso = curso;
}