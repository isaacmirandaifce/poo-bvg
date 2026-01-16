#include "Aluno.h"
#include <iostream>

// Construtor padrão
Aluno::Aluno() : nome(""), matricula(""), curso("") {}

// Construtor parametrizado
Aluno::Aluno(std::string nome, std::string matricula, std::string curso) 
    : nome(nome), matricula(matricula), curso(curso) {}

// Método para exibir informações
void Aluno::exibirInformacoes() const {
    std::cout << "\nInformações do Aluno:\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
}

// Getters
std::string Aluno::getNome() const { return nome; }
std::string Aluno::getMatricula() const { return matricula; }
std::string Aluno::getCurso() const { return curso; }

// Setters
void Aluno::setNome(std::string nome) { this->nome = nome; }
void Aluno::setMatricula(std::string matricula) { this->matricula = matricula; }
void Aluno::setCurso(std::string curso) { this->curso = curso; }