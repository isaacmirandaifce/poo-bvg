#include "Aluno.h"

Aluno::Aluno(int id, const std::string& nome) : id(id), nome(nome) {}

int Aluno::getId() const {
    return id;
}

std::string Aluno::getNome() const {
    return nome;
}