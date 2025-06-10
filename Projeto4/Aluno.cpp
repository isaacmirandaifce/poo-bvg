#include "Aluno.h"

Aluno::Aluno() : nome(""), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso) 
    : nome(nome), matricula(matricula), curso(curso) {}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}
