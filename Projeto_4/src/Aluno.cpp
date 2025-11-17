#include "../include/Aluno.h"
#include <iostream>

Aluno::Aluno(){
    nome = "";
    matricula = "";
    curso = "";
}

Aluno::Aluno(std::string nome, std::string matricula, std::string curso){
    this->nome = nome;
    this->matricula = matricula;
    this->curso = curso;
}

void Aluno::exibirInformacoes(){
    std::cout << "Informacoes do Aluno\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n\n";
}
