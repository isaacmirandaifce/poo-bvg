#include "Aluno.h"
#include <iostream>

// Implementação do construtor padrão
Aluno::Aluno() : nome(""), matricula(""), curso("") {}

// Implementação do construtor parametrizado
Aluno::Aluno(std::string nome, std::string matricula, std::string curso)
    : nome(nome), matricula(matricula), curso(curso) {}

// Implementação do método para exibir informações 
void Aluno::exibirInformacoes() const {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "INFORMACOES DO ALUNO" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

// Implementação do método para obter o nome
std::string Aluno::getNome() const {
    return nome;
}