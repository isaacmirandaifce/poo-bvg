#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& departamento)
    : nome(nome), departamento(departamento) {}

std::string Professor::getNome() const {
    return nome;
}

std::string Professor::getDepartamento() const {
    return departamento;
}

void Professor::adicionarDisciplinaLecionada(const std::string& disciplina) {
    disciplinasLecionadas.push_back(disciplina);
}

const std::vector<std::string>& Professor::getDisciplinasLecionadas() const {
    return disciplinasLecionadas;
}

void Professor::imprimir() const {
    std::cout << "Professor: " << nome << " (Departamento: " << departamento << ")" << std::endl;
}