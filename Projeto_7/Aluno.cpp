#include "Aluno.h"

Aluno::Aluno() : nome(""), media(0.0), ano(0) {}

Aluno::Aluno(std::string nome, double media, int ano)
    : nome(nome), media(media), ano(ano) {}

std::string Aluno::getNome() const {
    return nome;
}

double Aluno::getMedia() const {
    return media;
}

int Aluno::getAno() const {
    return ano;
}
