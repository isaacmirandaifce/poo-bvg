#include "Aluno.h"
#include <iostream>

/* Construtor padrão */
Aluno::Aluno() : nome(""), matricula(""), curso("") {}

/* Construtor parametrizado */
Aluno::Aluno(std::string nome, std::string matricula, std::string curso)
    : nome(nome), matricula(matricula), curso(curso) {}

/* informações do aluno */
void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}

/* Getters */
std::string Aluno::getNome() const { return nome; }
std::string Aluno::getMatricula() const { return matricula; }
std::string Aluno::getCurso() const { return curso; }
