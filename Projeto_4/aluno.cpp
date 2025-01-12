//cabeçalho classe aluno
#include "Aluno.h"
#include <iostream>

//construtor padrão
Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(std::string nome, std::string matricula, std::string curso)
    : nome(nome), matricula(matricula), curso(curso) {}


//exibindo informações do aluno
void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}

//acessando atributos privados
std::string Aluno::getNome() const { return nome; }
std::string Aluno::getMatricula() const { return matricula; }
std::string Aluno::getCurso() const { return curso; }
