#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(std::string nome, std::string matricula, std::string curso)
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n"
              << "Matricula: " << matricula << "\n"
              << "Curso: " << curso << "\n";
}
