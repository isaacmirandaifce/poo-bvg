#include "Disciplina.h"

Disciplina::Disciplina(int id, const std::string& nome, int professorId)
    : id(id), nome(nome), professorId(professorId) {}

int Disciplina::getId() const {
    return id;
}

std::string Disciplina::getNome() const {
    return nome;
}

int Disciplina::getProfessorId() const {
    return professorId;
}