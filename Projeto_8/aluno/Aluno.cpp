#include "Aluno.h"
#include <iostream>

//implementa o construtor da classe aluno
Aluno::Aluno(std::string nome, std::string id, std::string curso) : nome(nome), id(id), curso(curso) {}

//metodo para mostrar informações do aluno
void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nID: " << id << "\nCurso: " << curso << std::endl;
}
