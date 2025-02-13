#include "Aluno.h"

Aluno::Aluno(std::string nome, double media) : nome(nome), media(media) {}

std::string Aluno::getNome() const {
    return nome;
}

double Aluno::getMedia() const {
    return media;
}