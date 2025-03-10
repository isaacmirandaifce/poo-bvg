#include "Professor.h"

Professor::Professor(int id, const std::string& nome) : id(id), nome(nome) {}

int Professor::getId() const {
    return id;
}

std::string Professor::getNome() const {
    return nome;
}