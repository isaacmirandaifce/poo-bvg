#include "Professor.h"

Professor::Professor(std::string nome, std::string disciplina) : nome(nome), disciplina(disciplina) {}

std::string Professor::getNome() const {
    return nome;
}

std::string Professor::getDisciplina() const {
    return disciplina;
}