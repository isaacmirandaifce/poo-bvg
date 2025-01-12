#include "Aluno.h"
#include <iostream>

// Construtor inicializa os atributos com valores padrão
Aluno::Aluno() : nome(""), matricula(""), curso("") {}

// Construtor parametrizado que inicializa os atributos com valores valores fornecidos
Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso)
    : nome(nome), matricula(matricula), curso(curso) {}

// Exibe as informações do aluno
void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n"
              << "Matricula: " << matricula << "\n"
              << "Curso: " << curso << "\n";
}

// Getters 
std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::getMatricula() const {
    return matricula;
}

std::string Aluno::getCurso() const {
    return curso;
}
