#include "Professor.h"

Professor::Professor(const std::string& nome, const std::string& disciplinaMinistrada)
    : nome(nome), disciplinaMinistrada(disciplinaMinistrada) {}

const std::string& Professor::getNome() const {
    return nome;
}

const std::string& Professor::getDisciplinaMinistrada() const {
    return disciplinaMinistrada;
}

void Professor::imprimir() const {
    std::cout << "Professor: " << nome << " | Disciplina: " << disciplinaMinistrada << std::endl;
}
